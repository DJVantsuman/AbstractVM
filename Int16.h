#ifndef INT16_H
#define INT16_H

#include "ioperand.h"
#include "eoperandtype.h"
#include "factory.h"
#include "VMException.h"
#include <string>

class Int16 : public IOperand
{
private:
    std::string         _value;
    eOperandType const  _type = eOperandType::INT16;
    int                 _precision = 2;

    Int16();
    Int16(Int16 const &src);

public:
    Int16(std::string value);
    ~Int16();

    Int16            &operator=(Int16 const &rhs);

    virtual int             getPrecision( void ) const override;
    virtual eOperandType    getType( void ) const override;
    std::string             getValue() const override;

    virtual IOperand const  *operator+( IOperand const & rhs ) const override;
    virtual IOperand const  *operator-( IOperand const & rhs ) const override;
    virtual IOperand const  *operator*( IOperand const & rhs ) const override;
    virtual IOperand const  *operator/( IOperand const & rhs ) const override;
    virtual IOperand const  *operator%( IOperand const & rhs ) const override;

    virtual std::string const &toString( void ) const override;
};

#endif // INT16_H
