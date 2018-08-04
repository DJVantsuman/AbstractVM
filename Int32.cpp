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
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type < eOperandType::FLOAT)
        return Factory::instance().createOperand(type, std::to_string(std::stoll(this->_value) + std::stoll(rhs.getValue())));
    else
        return Factory::instance().createOperand(type, std::to_string(std::stold(this->_value) + std::stold(rhs.getValue())));
}

IOperand const * Int32::operator-( IOperand const &rhs ) const
{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type < eOperandType::FLOAT)
        return Factory::instance().createOperand(type, std::to_string(std::stoll(this->_value) - std::stoll(rhs.getValue())));
    else
        return Factory::instance().createOperand(type, std::to_string(std::stold(this->_value) - std::stold(rhs.getValue())));
}

IOperand const * Int32::operator*( IOperand const &rhs ) const
{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type < eOperandType::FLOAT)
        return Factory::instance().createOperand(type, std::to_string(std::stoll(this->_value) * std::stoll(rhs.getValue())));
    else
        return Factory::instance().createOperand(type, std::to_string(std::stold(this->_value) * std::stold(rhs.getValue())));
}

IOperand const * Int32::operator/( IOperand const &rhs ) const
{
    if (std::stold(rhs.getValue()) == 0)
        throw (VMException("EXCEPTION: Division by 0."));
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type < eOperandType::FLOAT)
        return Factory::instance().createOperand(type, std::to_string(std::stoll(this->_value) / std::stoll(rhs.getValue())));
    else
        return Factory::instance().createOperand(type, std::to_string(std::stold(this->_value) / std::stold(rhs.getValue())));
}

IOperand const * Int32::operator%( IOperand const &rhs ) const
{
    if (std::stold(rhs.getValue()) == 0)
        throw (VMException("EXCEPTION: Modulo by 0."));
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type < eOperandType::FLOAT)
        return Factory::instance().createOperand(type, std::to_string(std::stoll(this->_value) % std::stoll(rhs.getValue())));
    else
        return Factory::instance().createOperand(type, std::to_string(static_cast<int64_t >(std::stold(this->_value)) % static_cast<int64_t >(std::stold(rhs.getValue()))));
}

std::string const & Int32::toString( void ) const
{
    return _value;
}
