#include "stackvm.h"

#include "ioperand.h"
#include "eoperandtype.h"
#include "int8.h"

StackVM::StackVM() { }
StackVM::StackVM(StackVM const &src) { *this = src; }
StackVM::~StackVM() { }

StackVM &StackVM::operator=(StackVM const &rhs)
{
//    if (this != &rhs)
//        _value = rhs.getValue();
    return *this;
}
