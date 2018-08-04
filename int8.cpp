/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 23:25:52 by itsuman           #+#    #+#             */
/*   Updated: 2018/07/20 23:25:55 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type < eOperandType::FLOAT)
        return Factory::instance().createOperand(type, std::to_string(std::stoll(this->_value) + std::stoll(rhs.getValue())));
    else
        return Factory::instance().createOperand(type, std::to_string(std::stold(this->_value) + std::stold(rhs.getValue())));
}

IOperand const * Int8::operator-( IOperand const &rhs ) const
{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type < eOperandType::FLOAT)
        return Factory::instance().createOperand(type, std::to_string(std::stoll(this->_value) - std::stoll(rhs.getValue())));
    else
        return Factory::instance().createOperand(type, std::to_string(std::stold(this->_value) - std::stold(rhs.getValue())));
}

IOperand const * Int8::operator*( IOperand const &rhs ) const
{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type < eOperandType::FLOAT)
        return Factory::instance().createOperand(type, std::to_string(std::stoll(this->_value) * std::stoll(rhs.getValue())));
    else
        return Factory::instance().createOperand(type, std::to_string(std::stold(this->_value) * std::stold(rhs.getValue())));
}

IOperand const * Int8::operator/( IOperand const &rhs ) const
{
    if (std::stold(rhs.getValue()) == 0)
        throw (VMException("EXCEPTION: Division by 0."));
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type < eOperandType::FLOAT)
        return Factory::instance().createOperand(type, std::to_string(std::stoll(this->_value) / std::stoll(rhs.getValue())));
    else
        return Factory::instance().createOperand(type, std::to_string(std::stold(this->_value) / std::stold(rhs.getValue())));
}

IOperand const * Int8::operator%( IOperand const &rhs ) const
{
    if (std::stold(rhs.getValue()) == 0)
        throw (VMException("EXCEPTION: Modulo by 0."));
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type < eOperandType::FLOAT)
        return Factory::instance().createOperand(type, std::to_string(std::stoll(this->_value) % std::stoll(rhs.getValue())));
    else
        return Factory::instance().createOperand(type, std::to_string(static_cast<int64_t >(std::stold(this->_value)) % static_cast<int64_t >(std::stold(rhs.getValue()))));
}

std::string const & Int8::toString( void ) const
{
    return _value;
}
