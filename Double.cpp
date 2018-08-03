//
// Created by Ivan Tsuman on 8/3/18.
//

#include "Double.h"

Double::Double(){ }
Double::Double(Double const &src) { *this = src; }
Double::Double(std::string value) { _value = value; }

Double::~Double(){ }

int             Double::getPrecision( void ) const { return _precision; }
eOperandType    Double::getType( void ) const { return this->_type; }
std::string     Double::getValue() const      { return _value; }

Double    &Double::operator=( Double const &rhs )
{
    if (this != &rhs)
        _value = rhs.getValue();
    return *this;
}

IOperand const * Double::operator+( IOperand const &rhs ) const
{
    int result = std::stold(this->_value) + std::stold(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Double::operator-( IOperand const &rhs ) const
{
    int result = std::stold(this->_value) - std::stold(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Double::operator*( IOperand const &rhs ) const
{
    int result = std::stold(this->_value) * std::stold(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Double::operator/( IOperand const &rhs ) const
{
    if (std::stold(rhs.getValue()) == 0)
        throw (VMException("EXCEPTION: Division by 0."));
    int result = std::stold(this->_value) / std::stold(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Double::operator%( IOperand const &rhs ) const
{
    if (std::stold(rhs.getValue()) == 0)
        throw (VMException("EXCEPTION: Modulo by 0."));
    auto result = static_cast<int64_t >(std::stold(this->_value)) % static_cast<int64_t >(std::stold(rhs.getValue()));
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

std::string const & Double::toString( void ) const
{
    return _value;
}