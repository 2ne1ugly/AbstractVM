#include "Operand.hpp"
#include "Exceptions.hpp"


int Operand::getPrecision(void) const
{
	return (int)_type;
}

eOperandType Operand::getType(void) const
{
	return _type;
}

IOperand const* Operand::operator+(IOperand const& rhs) const
{
	eOperandType	outOperand = std::max(_type, rhs.getType());
	std::string		outString;
	OperandFactory	factory;
	if (outOperand <= eOperandType::Int32)
	{
		long long val1 = std::stoll(toString());
		long long val2 = std::stoll(rhs.toString());
		outString = std::to_string(val1 + val2);
	}
	else
	{
		long double val1 = std::stold(toString());
		long double val2 = std::stold(rhs.toString());
		outString = std::to_string(val1 + val2);
	}
	return factory.createOperand(outOperand, outString);
}

IOperand const* Operand::operator-(IOperand const& rhs) const
{
	eOperandType	outOperand = std::max(_type, rhs.getType());
	std::string		outString;
	OperandFactory	factory;
	if (outOperand <= eOperandType::Int32)
	{
		long long val1 = std::stoll(toString());
		long long val2 = std::stoll(rhs.toString());
		outString = std::to_string(val1 - val2);
	}
	else
	{
		long double val1 = std::stold(toString());
		long double val2 = std::stold(rhs.toString());
		outString = std::to_string(val1 - val2);
	}
	return factory.createOperand(outOperand, outString);
}

IOperand const* Operand::operator*(IOperand const& rhs) const
{
	eOperandType	outOperand = std::max(_type, rhs.getType());
	std::string		outString;
	OperandFactory	factory;
	if (outOperand <= eOperandType::Int32)
	{
		long long val1 = std::stoll(toString());
		long long val2 = std::stoll(rhs.toString());
		outString = std::to_string(val1 * val2);
	}
	else
	{
		long double val1 = std::stold(toString());
		long double val2 = std::stold(rhs.toString());
		outString = std::to_string(val1 * val2);
	}
	return factory.createOperand(outOperand, outString);
}

IOperand const* Operand::operator/(IOperand const& rhs) const
{
	eOperandType	outOperand = std::max(_type, rhs.getType());
	std::string		outString;
	OperandFactory	factory;
	if (outOperand <= eOperandType::Int32)
	{
		long long val1 = std::stoll(toString());
		long long val2 = std::stoll(rhs.toString());
		if (val2 == 0)
			throw DivisionByZero();
		outString = std::to_string(val1 / val2);
	}
	else
	{
		long double val1 = std::stold(toString());
		long double val2 = std::stold(rhs.toString());
		if (val2 == 0)
			throw DivisionByZero();
		outString = std::to_string(val1 / val2);
	}
	return factory.createOperand(outOperand, outString);
}

IOperand const* Operand::operator%(IOperand const& rhs) const
{
	eOperandType	outOperand = std::max(_type, rhs.getType());
	std::string		outString;
	OperandFactory	factory;
	if (outOperand <= eOperandType::Int32)
	{
		long long val1 = std::stoll(toString());
		long long val2 = std::stoll(rhs.toString());
		if (val2 == 0)
			throw ModuloByZero();
		outString = std::to_string(val1 % val2);
	}
	else
	{
		long double val1 = std::stold(toString());
		long double val2 = std::stold(rhs.toString());
		if (val2 == 0)
			throw ModuloByZero();
		outString = std::to_string(std::fmod(val1, val2));
	}
	return factory.createOperand(outOperand, outString);
}

std::string const& Operand::toString() const
{
	return _string;
}

Operand::Operand(std::string string, eOperandType type) : _string(string), _type(type)
{
}
