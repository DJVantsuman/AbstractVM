/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 01:22:14 by itsuman           #+#    #+#             */
/*   Updated: 2018/07/18 01:22:25 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include "ioperand.h"
#include "eoperandtype.h"
#include "VMException.h"
#include "int8.h"
#include "Int16.h"
#include "Int32.h"
#include "Float.h"
#include "Double.h"

class Factory
{
private:
    Factory();
    ~Factory();

    IOperand const  *createInt8( std::string const & value ) const;
    IOperand const  *createInt16( std::string const & value ) const;
    IOperand const  *createInt32( std::string const & value ) const;
    IOperand const  *createFloat( std::string const & value ) const;
    IOperand const  *createDouble( std::string const & value ) const;

public:
    static Factory &instance();
    IOperand const * createOperand( eOperandType type, std::string const & value ) const;
};

#endif // FACTORY_H
