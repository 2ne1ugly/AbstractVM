#pragma once

#include "IOperand.hpp"
#include "OperandFactory.hpp"

class Operand : public IOperand
{
public:
	virtual int getPrecision(void) const; // Precision of the type of the instance
	virtual eOperandType getType(void) const; // Type of the instance
	virtual IOperand const* operator+(IOperand const& rhs) const; // Sum
	virtual IOperand const* operator-(IOperand const& rhs) const; // Difference
	virtual IOperand const* operator*(IOperand const& rhs) const; // Product
	virtual IOperand const* operator/(IOperand const& rhs) const; // Quotient
	virtual IOperand const* operator%(IOperand const& rhs) const; // Modulo
	virtual std::string const& toString(void) const = 0; // String representation of the instance

	Operand();
	Operand(Operand& o);
	Operand& operator=(Operand& o);
	virtual ~Operand();

protected:
	unsigned long long _value = 0;
	eOperandType _type = 0;
};
