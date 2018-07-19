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
    return nullptr;
}

void VirtualMachine::mathIt(eOperandType type, std::string number) {

}

void VirtualMachine::push(const IOperand *operand) {
    stack.push_front(operand);
    size++;
}

void VirtualMachine::pop() {
    stack.pop_front();
    size--;
}

void VirtualMachine::dump() {
    for (auto it = stack.begin(); it != stack.end(); it++)
        std::cout << (*it)->toString() << std::endl;
}

void VirtualMachine::assert(const IOperand *operand) {

}

void VirtualMachine::add() {
    if(stack.size() > 1) {
        const  IOperand *newOperand;
        if (stack[0]->getPrecision() > stack[1]->getPrecision())
            newOperand = stack[0]->operator+(*stack[1]);
        else
            newOperand = stack[1]->operator+(*stack[0]);
        pop();
        pop();
        push(newOperand);
    } else throw (VMException("EXCEPTION: The stack is composed of strictly "
                              "less that two values when an arithmetic "
                              "instruction is executed."));
}

void VirtualMachine::sub() {
    if(stack.size() > 1) {
        const  IOperand *newOperand;
        if (stack[0]->getPrecision() > stack[1]->getPrecision())
            newOperand = stack[0]->operator-(*stack[1]);
        else
            newOperand = stack[1]->operator-(*stack[0]);
        pop();
        pop();
        push(newOperand);
    } else throw (VMException("EXCEPTION: The stack is composed of strictly "
                                      "less that two values when an arithmetic "
                                      "instruction is executed."));
}

void VirtualMachine::mul() {
    if(stack.size() > 1) {
        const  IOperand *newOperand;
        if (stack[0]->getPrecision() > stack[1]->getPrecision())
            newOperand = stack[0]->operator*(*stack[1]);
        else
            newOperand = stack[1]->operator*(*stack[0]);
        pop();
        pop();
        push(newOperand);
    } else throw (VMException("EXCEPTION: The stack is composed of strictly "
                                      "less that two values when an arithmetic "
                                      "instruction is executed."));
}

void VirtualMachine::div() {
    if (stack[1]->getValue() == "0" || stack[1]->getValue() == "0.0")
        throw (VMException("EXCEPTION: Division by 0."));
    else if(stack.size() > 1) {
        const  IOperand *newOperand;
        if (stack[0]->getPrecision() > stack[1]->getPrecision())
            newOperand = stack[0]->operator/(*stack[1]);
        else
            newOperand = stack[1]->operator/(*stack[0]);
        pop();
        pop();
        push(newOperand);
    } else throw (VMException("EXCEPTION: The stack is composed of strictly "
                                      "less that two values when an arithmetic "
                                      "instruction is executed."));
}

void VirtualMachine::mod() {

}

void VirtualMachine::print() {

}
