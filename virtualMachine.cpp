/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtualMachine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 21:24:55 by itsuman           #+#    #+#             */
/*   Updated: 2018/07/14 21:25:14 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtualMachine.h"

VirtualMachine::VirtualMachine(){ }
VirtualMachine::VirtualMachine(VirtualMachine const &src) { *this = src; }
VirtualMachine::~VirtualMachine(){ }
VirtualMachine    &VirtualMachine::operator=( VirtualMachine const &rhs )
{
    return *this;
}

void VirtualMachine::executeComand(std::string comand, std::string type, std::string value)
{
//    std::cout << "comand: " << comand << "; type: " << type << "; value: " << value << std::endl;
}
