//
// Created by Ivan Tsuman on 8/3/18.
//

#include <iostream>
#include "Int32.h"

Int32::Int32(){ }
Int32::Int32(Int32 const &src) { *this = src; }
Int32::Int32(std::string value) { _value = value; }

Int32::~Int32(){ }

int             Int32::getPrecision( void ) const { return _precision; }
eOperandType    Int32::getType( void ) const { return this->_type; }
std::string     Int32::getValue() const      { return _value; }

Int32    &Int32::operator=( Int32 const &rhs )
{
    if (this != &rhs)
        _value = rhs.getValue();
    return *this;
}

IOperand const * Int32::operator+( IOperand const &rhs ) const
{
    int result = std::stoi(this->_value) + std::stoi(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Int32::operator-( IOperand const &rhs ) const
{
    int result = std::stoi(this->_value) - std::stoi(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Int32::operator*( IOperand const &rhs ) const
{
    int result = std::stoi(this->_value) * std::stoi(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Int32::operator/( IOperand const &rhs ) const
{
    if (std::stoi(rhs.getValue()) == 0)
        throw (VMException("EXCEPTION: Division by 0."));
    int result = std::stoi(this->_value) / std::stoi(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Int32::operator%( IOperand const &rhs ) const
{
    if (std::stoi(rhs.getValue()) == 0)
        throw (VMException("EXCEPTION: Modulo by 0."));
    int result = std::stoi(this->_value) % std::stoi(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

std::string const & Int32::toString( void ) const
{
    return _value;
}
