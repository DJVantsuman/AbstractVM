//
// Created by Ivan Tsuman on 8/3/18.
//

#ifndef INT32_H
#define INT32_H

#include "ioperand.h"
#include "eoperandtype.h"
#include "factory.h"
#include "VMException.h"
#include <string>

class Int32 : public IOperand
{
private:
    std::string         _value;
    eOperandType const  _type = eOperandType::INT32;
    int                 _precision = 3;

    Int32();
    Int32(Int32 const &src);

public:
    Int32(std::string value);
    ~Int32();

    Int32            &operator=(Int32 const &rhs);

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

#endif
