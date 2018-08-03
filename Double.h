//
// Created by Ivan Tsuman on 8/3/18.
//

#ifndef DOUBLE_H
#define DOUBLE_H

#include "ioperand.h"
#include "eoperandtype.h"
#include "factory.h"
#include "VMException.h"
#include <string>

class Double : public IOperand
{
private:
    std::string         _value;
    eOperandType const  _type = eOperandType::DOUBLE;
    int                 _precision = 5;

    Double();
    Double(Double const &src);

public:
    Double(std::string value);
    ~Double();

    Double            &operator=(Double const &rhs);

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


#endif //DOUBLE_H
