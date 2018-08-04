//
// Created by Ivan Tsuman on 8/3/18.
//

#include "Float.h"

Float::Float(){ }
Float::Float(Float const &src) { *this = src; }
Float::Float(std::string value) { _value = value; }

Float::~Float(){ }

int             Float::getPrecision( void ) const { return _precision; }
eOperandType    Float::getType( void ) const { return this->_type; }
std::string     Float::getValue() const      { return _value; }

Float    &Float::operator=( Float const &rhs )
{
    if (this != &rhs)
        _value = rhs.getValue();
    return *this;
}

IOperand const * Float::operator+( IOperand const &rhs ) const
{
    auto result = std::stold(this->_value) + std::stold(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Float::operator-( IOperand const &rhs ) const
{
    auto result = std::stold(this->_value) - std::stold(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Float::operator*( IOperand const &rhs ) const
{
    auto result = std::stold(this->_value) * std::stold(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Float::operator/( IOperand const &rhs ) const
{
    if (std::stold(rhs.getValue()) == 0)
        throw (VMException("EXCEPTION: Division by 0."));
    auto result = std::stold(this->_value) / std::stold(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Float::operator%( IOperand const &rhs ) const
{
    if (std::stold(rhs.getValue()) == 0)
        throw (VMException("EXCEPTION: Modulo by 0."));
    auto result = static_cast<int64_t >(std::stold(this->_value)) % static_cast<int64_t >(std::stold(rhs.getValue()));
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

std::string const & Float::toString( void ) const
{
    return _value;
}