#ifndef FACTORY_H
#define FACTORY_H

#include "ioperand.h"
#include "eoperandtype.h"

class Factory
{
public:
    Factory();
    ~Factory();

    IOperand const * createOperand( eOperandType type, std::string const & value ) const;

private:
    IOperand const  *createInt8( std::string const & value ) const;
};

#endif // FACTORY_H
