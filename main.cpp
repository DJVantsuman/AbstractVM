#include <iostream>
#include <regex>
#include "virtualMachine.h"
#include "VMException.h"

bool checkType(std::string type, std::string value)
{
    std::cmatch result;
    if (type == "int8" || type == "int16" || type == "int32") {
         std::regex regular("[0-9]+");
         return std::regex_match(value.c_str(), result, regular);
    }
    else if (type == "float" || type == "double") {
        std::regex regular("(\\d+|[0-9]*\\.[0-9]+)");
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
                               "(\\d+|[0-9]*\\.[0-9]+)"
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

void readFile(VirtualMachine &vm)
{
}

void readStdin(VirtualMachine &vm)
{
    std::string var = "";
    while (var != "end")
    {
        std::getline(std::cin, var);
        std::cout << var << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::cout << "The virtual machine welcomes you." << std::endl;
    static VirtualMachine& vm = VirtualMachine::instance();
    try {
        if (argc == 2)
            readFile(vm);
        else if (argc == 1)
            readStdin(vm);
    }
    catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
