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

VirtualMachine &VirtualMachine::instance()
{
    static VirtualMachine vm;
    return vm;
}

void VirtualMachine::executeComand(std::string command, std::string type, std::string value)
{
    if (command == "push")          push(getOperand(type,value));
    else if (command == "pop")      pop();
    else if (command == "dump")     dump();
    else if (command == "assert")   assert(getOperand(type,value));
    else if (command == "add")      add();
    else if (command == "sub")      sub();
    else if (command == "mul")      mul();
    else if (command == "div")      div();
    else if (command == "mod")      mod();
    else if (command == "print")    print();
}

const IOperand *VirtualMachine::getOperand(std::string type, std::string value) {
    if (type == "int8")
        return  Factory::instance().createOperand(eOperandType::INT8, value);
    else if (type == "int16")
        return Factory::instance().createOperand(eOperandType::INT16, value);
    else if (type == "int32")
        return Factory::instance().createOperand(eOperandType::INT32, value);
    else if (type == "float")
        return Factory::instance().createOperand(eOperandType::FLOAT, value);
    else if (type == "double")
        return Factory::instance().createOperand(eOperandType::DOUBLE, value);
}

void VirtualMachine::push(const IOperand *operand) {
    stack.push(operand);
    size++;
}

void VirtualMachine::pop() {
    stack.pop();
    size--;
}

void VirtualMachine::dump() {

}

void VirtualMachine::assert(const IOperand *operand) {

}

void VirtualMachine::add() {

}

void VirtualMachine::sub() {

}

void VirtualMachine::mul() {

}

void VirtualMachine::div() {

}

void VirtualMachine::mod() {

}

void VirtualMachine::print() {

}
