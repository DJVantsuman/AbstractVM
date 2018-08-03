#include <iostream>
#include "Int16.h"

Int16::Int16(){ }
Int16::Int16(Int16 const &src) { *this = src; }
Int16::Int16(std::string value) { _value = value; }

Int16::~Int16(){ }

int             Int16::getPrecision( void ) const { return _precision; }
eOperandType    Int16::getType( void ) const { return this->_type; }
std::string     Int16::getValue() const      { return _value; }

Int16    &Int16::operator=( Int16 const &rhs )
{
    if (this != &rhs)
        _value = rhs.getValue();
    return *this;
}

IOperand const * Int16::operator+( IOperand const &rhs ) const
{
    int result = std::stoi(this->_value) + std::stoi(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Int16::operator-( IOperand const &rhs ) const
{
    int result = std::stoi(this->_value) - std::stoi(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Int16::operator*( IOperand const &rhs ) const
{
    int result = std::stoi(this->_value) * std::stoi(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Int16::operator/( IOperand const &rhs ) const
{
    if (std::stoi(rhs.getValue()) == 0)
        throw (VMException("EXCEPTION: Division by 0."));
    int result = std::stoi(this->_value) / std::stoi(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Int16::operator%( IOperand const &rhs ) const
{
    if (std::stoi(rhs.getValue()) == 0)
        throw (VMException("EXCEPTION: Modulo by 0."));
    int result = std::stoi(this->_value) % std::stoi(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

std::string const & Int16::toString( void ) const
{
    return _value;
}
