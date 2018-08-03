//
// Created by Ivan Tsuman on 8/3/18.
//

#ifndef FLOAT_H
#define FLOAT_H


#include "ioperand.h"
#include "eoperandtype.h"
#include "factory.h"
#include "VMException.h"
#include <string>

class Float : public IOperand
{
private:
    std::string         _value;
    eOperandType const  _type = eOperandType::FLOAT;
    int                 _precision = 4;

    Float();
    Float(Float const &src);

public:
    Float(std::string value);
    ~Float();

    Float            &operator=(Float const &rhs);

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


#endif //FLOAT_H
