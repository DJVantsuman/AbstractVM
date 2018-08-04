#include <iostream>
#include <fstream>
#include <regex>
#include "virtualMachine.h"
#include "VMException.h"

bool checkType(std::string type, std::string value)
{
    std::cmatch result;
    if (type == "int8" || type == "int16" || type == "int32") {
         std::regex regular("-?[0-9]+");
         return std::regex_match(value.c_str(), result, regular);
    }
    else if (type == "float" || type == "double") {
        std::regex regular("(-?\\d+|[0-9]*\\.[0-9]+)");
        return std::regex_match(value.c_str(), result, regular);
    }
    return false;
}

void validate(std::string str, VirtualMachine &vm)
{
    std::cmatch result;
    std::regex command("(;|push|pop|dump|assert|add|sub|mul|div|mod|print|exit)"
                       "([\\w\\W]*)");
    if (std::regex_match(str.c_str(), result, command)) {
        std::string comand = result[1];
        std::string type = result[2];
        if (comand == "push" || comand == "assert") {
            std::regex regular("(push|assert)"
                               "( )+"
                               "(int8|int16|int32|float|double)"
                               "(\\()"
                               "(-?\\d+|[0-9]*\\.[0-9]+)"
                               "((\\))|(\\) *;.*))");
            if (std::regex_match(str.c_str(), result, regular)) {
                if (checkType(result[3], result[5])) {
                    vm.executeComand(comand, result[3], result[5]);
                } else throw VMException("EXCEPTION: Wrong type of the passed parameter: " + static_cast<std::string>(result[5]));
            } else throw VMException("EXCEPTION: Wrong type of argument: " + type);
        }
        else vm.executeComand(comand);
    } else throw VMException("EXCEPTION: An instruction is unknown: " + str);
}

void readFile(VirtualMachine &vm, std::string file)
{
    bool f = false;
    std::string buff;
    std::vector<std::string> commands;
    std::ifstream fin(file);
    std::cmatch result;
    std::regex regular("(exit\\s?(;.*)?)");
    if(fin.is_open() && fin.good()) {
        while (getline(fin, buff))
        {
            if(std::regex_match(buff.c_str(), result, regular)) {
                f = true;
                break;
            }
            commands.push_back(buff);
        }
        if(f) {
            for (int i = 0; i < static_cast<int>(commands.size()); i++)
            {
                try {
                    validate(commands[i], vm);
                }
                catch (std::exception &ex) {
                    std::string massage = ex.what();
                    throw (VMException(massage + "\n" + "Line " + std::to_string(i) + ": " + commands[i]));
                }
            }
        }
        else throw VMException("EXCEPTION: The program has wrong instructions or exit instruction is absent.");
    }
    else throw VMException("EXCEPTION: Can not open file \"" + file + "\" or it does not exist.");
}

void readStdin(VirtualMachine &vm)
{
    std::string var = "";
    std::cmatch result;
    std::regex regular("(;;\\s?(;.*)?)");
    while (std::getline(std::cin, var))
    {
        if (std::regex_match(var.c_str(), result, regular))
            exit(0);
        validate(var,vm);
    }
}

void printMan()
{
    std::cout << "\n>>>>>>>>>>>>>>>>>>>>> -- AVM Man -- <<<<<<<<<<<<<<<<<<<<<\n" << std::endl;

    std::cout << "push v:   Pushes the value v at the top of the stack." << std::endl;
    std::cout << "pop:      Unstacks the value from the top of the stack." << std::endl;
    std::cout << "dump:     Displays each value of the stack." << std::endl;
    std::cout << "assert v: Asserts that the value at the top of the stack\n"
                 "          is equal to the one passed." << std::endl;
    std::cout << "add:      Unstacks the first two values on the stack, adds\n"
                 "          them together and stacks the result." << std::endl;
    std::cout << "sub:      Unstacks the first two values on the stack,\n"
                 "          subtracts them, then stacks the result." << std::endl;
    std::cout << "mul:      Unstacks the first two values on the stack,\n"
                 "          multiplies them, then stacks the result." << std::endl;
    std::cout << "div:      Unstacks the first two values on the stack,\n"
                 "          divides them, then stacks the result." << std::endl;
    std::cout << "mod:      Unstacks the first two values on the stack,\n"
                 "          calculates the modulus, then stacks the result." << std::endl;
    std::cout << "print:    Displays the corresponding character on the\n"
                 "          standard output." << std::endl;
    std::cout << "exit:     Terminate the execution of the current program." << std::endl;

    std::cout << "\n\";\":      Beginning of a comment." << std::endl;
    std::cout << "\";;\":     End of a program read from the standard input" << std::endl;
}

int main(int argc, char *argv[])
{
    try {
        if (argc == 2)
        {
            std::string arg = argv[1];
            if (arg == "--help")
                printMan();
            else
                readFile(VirtualMachine::instance(), argv[1]);
        }
        else if (argc == 1)
            readStdin(VirtualMachine::instance());
    }
    catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
