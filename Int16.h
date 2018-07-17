#ifndef INT16_H
#define INT16_H

#include "ioperand.h"
#include "eoperandtype.h"
#include <string>

class Int16 : public IOperand
{
private:
    std::string         _value;
    eOperandType const  _type = eOperandType::INT8;
    int                 _precision = 1;

    Int16();
    Int16(Int16 const &src);

public:
    Int16(std::string value);
    ~Int16();

    Int16            &operator=(Int16 const &rhs);

    virtual int             getPrecision( void ) const override;
    virtual eOperandType    getType( void ) const override;
    std::string             getValue() const;
//        void                    setValue(std::string value);

    virtual IOperand const  *operator+( IOperand const & rhs ) const override;
    virtual IOperand const  *operator-( IOperand const & rhs ) const override;
    virtual IOperand const  *operator*( IOperand const & rhs ) const override;
    virtual IOperand const  *operator/( IOperand const & rhs ) const override;
    virtual IOperand const  *operator%( IOperand const & rhs ) const override;

    virtual std::string const &toString( void ) const override;
};

#endif // INT16_H
