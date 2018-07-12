#include <iostream>
#include <string>
#include <regex>
#include "int8.h"

bool checkType(std::string type, std::string value)
{
    std::cmatch result;
    if (type == "int8" || type == "int16" || type == "int32") {
         std::regex regular("[0-9]+");
         return std::regex_match(value.c_str(), result, regular);
    }
    else if (type == "float" || type == "double"){
        std::regex regular("(\\d+|[0-9]*\\.[0-9]+)");
        return std::regex_match(value.c_str(), result, regular);
    }
    std::cout << type << ": " << value << std::endl;
    return false;
}

bool validate(std::string str)
{
    std::cmatch result;
    std::regex command("(;|push|pop|dump|assert|add|sub|mul|div|mod|print|exit)"
                       "([\\w\\W]*)");
    if (std::regex_match(str.c_str(), result, command)) {
        if (result[1] == "push" || result[1] == "assert") {
            std::regex regular("(push|assert)"
                               "( )+"
                               "(int8|int16|int32|float|double)"
                               "(\\()"
                               "(\\d+|[0-9]*\\.[0-9]+)"
                               "((\\))|(\\) *;.*))");
            if (std::regex_match(str.c_str(), result, regular))
                return (checkType(result[3], result[5]));
        }
        else return true;
    }
    return false;
}

int readFile()
{
    return 1;
}

int main(int argc, char *argv[])
{
    std::cout << "Hello world" << std::endl;
    if (argc < 3)
    {
        if (argc == 1)
        {
            std::string var = "";
            while (var != "end")
            {
                std::getline(std::cin, var);
                std::cout << var << std::endl;
                std::cout << validate(var) << std::endl;
            }
        }
    }
    return 0;
}
