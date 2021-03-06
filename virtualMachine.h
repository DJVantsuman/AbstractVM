/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtualMachine.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 21:24:21 by itsuman           #+#    #+#             */
/*   Updated: 2018/07/14 21:24:46 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H

#include <string>
#include <iostream>
#include <stack>
#include "ioperand.h"
#include "eoperandtype.h"
#include "factory.h"
#include "VMException.h"
#include "int8.h"

class VirtualMachine {
private:
    VirtualMachine();
    ~VirtualMachine();

    std::deque<const IOperand*> stack;
    int size;

    const IOperand *getOperand(std::string type, std::string value);

public:
    static VirtualMachine  &instance();
    void executeComand(std::string command, std::string type = "", std::string value = "");

private:
    void push(const IOperand *operand);
    void pop();
    void dump();
    int  assert(const IOperand *operand);
    void add();
    void sub();
    void mul();
    void div();
    void mod();
    void print();
};

#endif
