#include "Int16.h"

Int16::Int16(){ }
Int16::Int16(Int16 const &src) { *this = src; }
Int16::Int16(std::string value)   { _value = value; }

Int16::~Int16(){ }

int             Int16::getPrecision( void ) const { return _precision; }
eOperandType    Int16::getType( void ) const { return this->_type; }
std::string     Int16::getValue() const      { return _value; }
//void            Int16::setValue(std::string value)   { _value = value; }

Int16    &Int16::operator=( Int16 const &rhs )
{
    if (this != &rhs)
        _value = rhs.getValue();
    return *this;
}

IOperand const * Int16::operator+( IOperand const &rhs ) const
{
    return new Int16("");
}

IOperand const * Int16::operator-( IOperand const &rhs ) const
{
    return new Int16("");
}

IOperand const * Int16::operator*( IOperand const &rhs ) const
{
    return new Int16("");
}

IOperand const * Int16::operator/( IOperand const &rhs ) const
{
    return new Int16("");
}

IOperand const * Int16::operator%( IOperand const &rhs ) const
{
    return new Int16("");
}

std::string const & Int16::toString( void ) const
{
    return "";
}
