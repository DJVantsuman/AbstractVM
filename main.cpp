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
    std::cout << type << ": " << value << std::endl;
    return false;
}

void validate(std::string str, VirtualMachine &vm)
{
    std::cmatch result;
    std::regex command("(;|push|pop|dump|assert|add|sub|mul|div|mod|print|exit)"
                       "([\\w\\W]*)");
    if (std::regex_match(str.c_str(), result, command)) {
        std::string comand = result[1];
        if (comand == "push" || comand == "assert") {
            std::regex regular("(push|assert)"
                               "( )+"
                               "(int8|int16|int32|float|double)"
                               "(\\()"
                               "(-?\\d+|[0-9]*\\.[0-9]+)"
                               "((\\))|(\\) *;.*))");
            if (std::regex_match(str.c_str(), result, regular))
                if (checkType(result[3], result[5]))
                    vm.executeComand(comand, result[3], result[5]);
                else throw (VMException("EXCEPTION: An instruction is unknown."));
        }
        else if (comand != "exit")
            vm.executeComand(comand);
        else exit(1);
    } else throw (VMException("EXCEPTION: An instruction is unknown."));
}

void readFile(VirtualMachine &vm, std::string file)
{
    bool f = false;
    std::string buff;
    std::vector<std::string> commands;
    std::ifstream fin(file);
    std::cmatch result;
    std::regex regular("(exit\\s?(;.*)?)");
    if(fin.is_open() && fin.good())
    {
        while (getline(fin, buff))
        {
            if(std::regex_match(buff.c_str(), result, regular))
            {
                f = true;
                break;
            }
            commands.push_back(buff);
        }
        if (f)
        {
            for (int i = 0; i < commands.size(); i++)
            {
                try {
                    validate(commands[i], vm);
                }
                catch (std::exception &ex){
                    std::string massage = ex.what();
                    throw (VMException(massage + "\n" + "Line " + std::to_string(i) + ": " + commands[i]));
                }
            }
        }
        else
            throw VMException("EXCEPTION: The program doesn’t have an exit instruction.");
    }
    else
        throw VMException("EXCEPTION: Can not open file \"" + file + "\" or it does not exist.");
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

int main(int argc, char *argv[])
{
    std::cout << "The virtual machine welcomes you." << std::endl;
    static VirtualMachine& vm = VirtualMachine::instance();
    try {
        if (argc == 2)
            readFile(vm, argv[1]);
        else if (argc == 1)
            readStdin(vm);
    }
    catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
