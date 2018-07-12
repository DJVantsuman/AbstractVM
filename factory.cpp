#include "factory.h"
#include "int8.h"

Factory::Factory() { }
Factory::~Factory() { }

IOperand const  *Factory::createOperand(eOperandType type, const std::string &value) const
{
    if (type == eOperandType::INT8)
        return createInt8(value);
    return NULL;
}

IOperand const  *Factory::createInt8(const std::string &value) const
{
    return new Int8(value);
}
