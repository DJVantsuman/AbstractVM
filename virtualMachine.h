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

class VirtualMachine {
public:
    VirtualMachine();
    VirtualMachine(VirtualMachine const &src);
    ~VirtualMachine();
    VirtualMachine &operator=(VirtualMachine const &rhs);

    void executeComand(std::string comand, std::string type = 0, std::string value = 0);
};

#endif
