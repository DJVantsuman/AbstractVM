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

#include <iostream>
#include "factory.h"
#include "int8.h"

Factory::Factory() { }
Factory::~Factory() { }

Factory &Factory::instance()
{
    static Factory factory;
    return factory;
}

IOperand const  *Factory::createOperand(eOperandType type, const std::string &value) const
{
    if (type == eOperandType::INT8) return createInt8(value);
    else if (type == eOperandType::INT16) return createInt16(value);
    return NULL;
}

IOperand const  *Factory::createInt8(const std::string &value) const
{
    return new Int8(value);
}

IOperand const  *Factory::createInt16(const std::string &value) const
{
    return new Int8(value);
}
