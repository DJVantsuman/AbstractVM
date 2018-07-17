#ifndef INT8_H
#define INT8_H

#include "ioperand.h"
#include "eoperandtype.h"
#include <string>

class Int8 : public IOperand
{
    private:
        std::string         _value;
        eOperandType const  _type = eOperandType::INT8;
        int                 _precision = 1;

        Int8();
        Int8(Int8 const &src);

    public:
        Int8(std::string value);
        ~Int8();

        Int8            &operator=(Int8 const &rhs);

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

#endif // INT8_H
