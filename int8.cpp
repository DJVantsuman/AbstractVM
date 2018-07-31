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
    int result = std::stoi(this->_value) + std::stoi(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Int8::operator-( IOperand const &rhs ) const
{
    int result = std::stoi(this->_value) - std::stoi(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Int8::operator*( IOperand const &rhs ) const
{
    int result = std::stoi(this->_value) * std::stoi(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Int8::operator/( IOperand const &rhs ) const
{
    if (std::stoi(rhs.getValue()) == 0)
        throw (VMException("EXCEPTION: Division by 0."));
    int result = std::stoi(this->_value) / std::stoi(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

IOperand const * Int8::operator%( IOperand const &rhs ) const
{
    if (std::stoi(rhs.getValue()) == 0)
        throw (VMException("EXCEPTION: Modulo by 0."));
    int result = std::stoi(this->_value) % std::stoi(rhs.getValue());
    eOperandType type = std::max(this->getType(), rhs.getType());
    return Factory::instance().createOperand(type, std::to_string(result));
}

std::string const & Int8::toString( void ) const
{
    return _value;
}
