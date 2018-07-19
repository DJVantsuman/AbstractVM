#include <iostream>
#include "int8.h"

Int8::Int8(){ }
Int8::Int8(Int8 const &src) { *this = src; }
Int8::Int8(std::string value) { _value = value; }

Int8::~Int8(){ }

int             Int8::getPrecision( void ) const { return _precision; }
eOperandType    Int8::getType( void ) const { return this->_type; }
std::string     Int8::getValue() const      { return _value; }

Int8    &Int8::operator=( Int8 const &rhs )
{
    if (this != &rhs)
        _value = rhs.getValue();
    return *this;
}

IOperand const * Int8::operator+( IOperand const &rhs ) const
{
    int result = std::stoi(this->_value) + std::stoi(rhs.getValue());
    return new Int8(std::to_string(result));
}

IOperand const * Int8::operator-( IOperand const &rhs ) const
{
    int result = std::stoi(this->_value) - std::stoi(rhs.getValue());
    return new Int8(std::to_string(result));
}

IOperand const * Int8::operator*( IOperand const &rhs ) const
{
    int result = std::stoi(this->_value) * std::stoi(rhs.getValue());
    return new Int8(std::to_string(result));
}

IOperand const * Int8::operator/( IOperand const &rhs ) const
{
    int result = std::stoi(this->_value) / std::stoi(rhs.getValue());
    return new Int8(std::to_string(result));
}

IOperand const * Int8::operator%( IOperand const &rhs ) const
{
    return new Int8("");
}

std::string const & Int8::toString( void ) const
{
    return _value;
}
