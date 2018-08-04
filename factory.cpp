/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 01:22:31 by itsuman           #+#    #+#             */
/*   Updated: 2018/07/18 01:22:39 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factory.h"

Factory::Factory() { }
Factory::~Factory() { }

Factory &Factory::instance()
{
    static Factory factory;
    return factory;
}

IOperand const  *Factory::createOperand(eOperandType type, const std::string &value) const
{
    typedef IOperand const * (Factory::*FuncType)(std::string const & value) const;
    FuncType funcArray[5];

    funcArray[eOperandType::INT8] = &Factory::createInt8;
    funcArray[eOperandType::INT16] = &Factory::createInt16;
    funcArray[eOperandType::INT32] = &Factory::createInt32;
    funcArray[eOperandType::FLOAT] = &Factory::createFloat;
    funcArray[eOperandType::DOUBLE] = &Factory::createDouble;

    return dynamic_cast<const IOperand *>((this->*funcArray[type])(value));
}

IOperand const  *Factory::createInt8(const std::string &value) const
{
    int n = std::stoi(value);
    if ((value[0] != '-' && value.size() > 3) || n > 255)
        throw (VMException("EXCEPTION: Overflow on a value."));
    else if ((value[0] == '-' && value.size() > 4) || n < -128)
        throw (VMException("EXCEPTION: Underflow on a value."));
    return new Int8(value);
}

IOperand const  *Factory::createInt16(const std::string &value) const
{
    int n = std::stoi(value);
    if ((value[0] != '-' && value.size() > 5) || n > 65535)
        throw (VMException("EXCEPTION: Overflow on a value."));
    else if ((value[0] == '-' && value.size() > 6) || n < -32768)
        throw (VMException("EXCEPTION: Underflow on a value."));
    return new Int16(value);
}

IOperand const  *Factory::createInt32(const std::string &value) const
{
    try {
        std::stoi(value);
    }
    catch (...)
    {
        if (value[0] != '-')
            throw (VMException("EXCEPTION: Overflow on a value."));
        else
            throw (VMException("EXCEPTION: Underflow on a value."));
    }
    return new Int32(value);
}

IOperand const  *Factory::createFloat(std::string const &value) const
{
    float result;
    try {
        result = std::stof(value);
    }
    catch (...)
    {
        if (value[0] != '-')
            throw (VMException("EXCEPTION: Overflow on a value."));
        else
            throw (VMException("EXCEPTION: Underflow on a value."));
    }
    return new Float(std::to_string(result));
}

IOperand const  *Factory::createDouble(std::string const &value) const
{
    double result;
    try {
        result = std::stod(value);
    }
    catch (...)
    {
        if (value[0] != '-')
            throw (VMException("EXCEPTION: Overflow on a value."));
        else
            throw (VMException("EXCEPTION: Underflow on a value."));
    }
    return new Double(std::to_string(result));
}