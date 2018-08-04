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
VirtualMachine::~VirtualMachine(){
    for (auto it = stack.begin(); it != stack.end(); it++)
        delete(*it);
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

void VirtualMachine::push(const IOperand *operand) {
    stack.push_front(operand);
    size++;
}

void VirtualMachine::pop() {
    if (stack.size() > 0) {
        stack.pop_front();
        size--;
    } else throw (VMException("EXCEPTION: Pop on an empty stack."));
}

void VirtualMachine::dump() {
    if (stack.size() > 0)
        for (auto it = stack.begin(); it != stack.end(); it++)
            std::cout << (*it)->toString() << std::endl;
    else std::cout << "Empty stack." << std::endl;
}

int VirtualMachine::assert(const IOperand *operand) {
    if (stack.size() > 0)
        if (stack[0]->getType() != operand->getType() ||
                stack[0]->getValue() != operand->getValue())
            throw (VMException("EXCEPTION: An assert instruction is not true."));
        else
            return 1;
    else throw (VMException("EXCEPTION: Assert on an empty stack."));
}

void VirtualMachine::add() {
    if(stack.size() > 1) {
        const  IOperand *newOperand = *stack[0] + *stack[1];
        delete(stack[0]);
        delete(stack[1]);
        pop();
        pop();
        push(newOperand);
    } else throw (VMException("EXCEPTION: The stack is composed of less that two values."));
}

void VirtualMachine::sub() {
    if(stack.size() > 1) {
        const  IOperand *newOperand = *stack[1] - *stack[0];
        delete(stack[0]);
        delete(stack[1]);
        pop();
        pop();
        push(newOperand);
    } else throw (VMException("EXCEPTION: The stack is composed of less that two values."));
}

void VirtualMachine::mul() {
    if(stack.size() > 1) {
        const  IOperand *newOperand = *stack[0] * *stack[1];
        delete(stack[0]);
        delete(stack[1]);
        pop();
        pop();
        push(newOperand);
    } else throw (VMException("EXCEPTION: The stack is composed of less that two values."));
}

void VirtualMachine::div() {
    if(stack.size() > 1) {
        const  IOperand *newOperand = *stack[1] / *stack[0];
        delete(stack[0]);
        delete(stack[1]);
        pop();
        pop();
        push(newOperand);
    } else throw (VMException("EXCEPTION: The stack is composed of less that two values."));
}

void VirtualMachine::mod() {
    if(stack.size() > 1) {
        const  IOperand *newOperand = *stack[1] % *stack[0];
        delete(stack[0]);
        delete(stack[1]);
        pop();
        pop();
        push(newOperand);
    } else throw (VMException("EXCEPTION: The stack is composed of less that two values."));
}

void VirtualMachine::print() {
    if (stack.size() < 1)
        throw (VMException("EXCEPTION: Print on an empty stack."));
    else if (stack[0]->getType() == eOperandType::INT8)
        std::cout << static_cast<char>(std::stoi(stack[0]->getValue())) << std::endl;
    else throw (VMException("EXCEPTION: An print instruction is not true"));
}
