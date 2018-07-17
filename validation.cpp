#include "validation.h"

Validation::Validation() { }
Validation::~Validation() { }

int Validation::check(std::string type, std::string value)
{
    if(type == "int8" || type == "int16" || type == "int32")
        return checkInt(value);
    else if(type == "float")
        return checkFloat(value);
    else if(type == "double")
        return checkDouble(value);
}

int Validation::checkInt(std::string value)
{

}

int Validation::checkFloat(std::string value)
{

}

int Validation::checkDouble(std::string value)
{

}