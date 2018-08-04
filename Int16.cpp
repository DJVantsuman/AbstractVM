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
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type < eOperandType::FLOAT)
        return Factory::instance().createOperand(type, std::to_string(std::stoll(this->_value) + std::stoll(rhs.getValue())));
    else
        return Factory::instance().createOperand(type, std::to_string(std::stold(this->_value) + std::stold(rhs.getValue())));
}

IOperand const * Int16::operator-( IOperand const &rhs ) const
{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type < eOperandType::FLOAT)
        return Factory::instance().createOperand(type, std::to_string(std::stoll(this->_value) - std::stoll(rhs.getValue())));
    else
        return Factory::instance().createOperand(type, std::to_string(std::stold(this->_value) - std::stold(rhs.getValue())));
}

IOperand const * Int16::operator*( IOperand const &rhs ) const
{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type < eOperandType::FLOAT)
        return Factory::instance().createOperand(type, std::to_string(std::stoll(this->_value) * std::stoll(rhs.getValue())));
    else
        return Factory::instance().createOperand(type, std::to_string(std::stold(this->_value) * std::stold(rhs.getValue())));
}

IOperand const * Int16::operator/( IOperand const &rhs ) const
{
    if (std::stold(rhs.getValue()) == 0)
        throw (VMException("EXCEPTION: Division by 0."));
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type < eOperandType::FLOAT)
        return Factory::instance().createOperand(type, std::to_string(std::stoll(this->_value) / std::stoll(rhs.getValue())));
    else
        return Factory::instance().createOperand(type, std::to_string(std::stold(this->_value) / std::stold(rhs.getValue())));
}

IOperand const * Int16::operator%( IOperand const &rhs ) const
{
    if (std::stold(rhs.getValue()) == 0)
        throw (VMException("EXCEPTION: Modulo by 0."));
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type < eOperandType::FLOAT)
        return Factory::instance().createOperand(type, std::to_string(std::stoll(this->_value) % std::stoll(rhs.getValue())));
    else
        return Factory::instance().createOperand(type, std::to_string(static_cast<int64_t >(std::stold(this->_value)) % static_cast<int64_t >(std::stold(rhs.getValue()))));
}

std::string const & Int16::toString( void ) const
{
    return _value;
}
