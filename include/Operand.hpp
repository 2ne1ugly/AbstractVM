#pragma once

#include "IOperand.hpp"
#include "Exceptions.hpp"
#include "OperandFactory.hpp"
#include "abstractVM.h"
#include <cmath>

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
	virtual std::string const& toString(void) const; // String representation of the instance

	Operand() = delete;
	Operand(std::string string, eOperandType type);
	Operand(Operand& o) = default;
	Operand& operator=(Operand& o) = default;
	virtual ~Operand() = default;

protected:
	std::string	_string;
	eOperandType _type = eOperandType::None;
};
