#include "int8.h"

Int8::Int8(){ }
Int8::Int8(Int8 const &src) { *this = src; }
Int8::Int8(std::string value)   { _value = value; }

Int8::~Int8(){ }

int             Int8::getPrecision( void ) const { return _precision; }
eOperandType    Int8::getType( void ) const { return this->_type; }
std::string     Int8::getValue() const      { return _value; }
//void            Int8::setValue(std::string value)   { _value = value; }

Int8    &Int8::operator=( Int8 const &rhs )
{
    if (this != &rhs)
        _value = rhs.getValue();
    return *this;
}

IOperand const * Int8::operator+( IOperand const &rhs ) const
{
}

IOperand const * Int8::operator-( IOperand const &rhs ) const
{
    return new Int8("");
}

IOperand const * Int8::operator*( IOperand const &rhs ) const
{
    return new Int8("");
}

IOperand const * Int8::operator/( IOperand const &rhs ) const
{
    return new Int8("");
}

IOperand const * Int8::operator%( IOperand const &rhs ) const
{
    return new Int8("");
}

std::string const & Int8::toString( void ) const
{
    return "";
}
