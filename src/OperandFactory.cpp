#include "OperandFactory.hpp"
#include "Exceptions.hpp"
#include <limits>
#include "Operand.hpp"

IOperand const *OperandFactory::createOperand(eOperandType type, std::string const& value) const
{
	switch (type)
	{
	case eOperandType::Int8:
		return createInt8(value);
		break;
	case eOperandType::Int16:
		return createInt16(value);
		break;
	case eOperandType::Int32:
		return createInt32(value);
		break;
	case eOperandType::Float:
		return createFloat(value);
		break;
	case eOperandType::Double:
		return createDouble(value);
		break;
	default:
		throw UnknownInstruction("unknown operand type");
	}
}

IOperand const* OperandFactory::createInt8(std::string const& value) const
{
	long long int test = std::stoll(value);
	if (test > std::numeric_limits<char>().max())
		throw OverflowInt8();
	if (test < std::numeric_limits<char>().lowest())
		throw UnderflowInt8();
	return new Operand(value, eOperandType::Int8);
}

IOperand const* OperandFactory::createInt16(std::string const& value) const
{
	long long int test = std::stoll(value);
	if (test > std::numeric_limits<short>().max())
		throw OverflowInt16();
	if (test < std::numeric_limits<short>().lowest())
		throw UnderflowInt16();
	return new Operand(value, eOperandType::Int16);
}

IOperand const* OperandFactory::createInt32(std::string const& value) const
{
	long long int test = std::stoll(value);
	if (test > std::numeric_limits<int>().max())
		throw OverflowInt32();
	if (test < std::numeric_limits<int>().lowest())
		throw UnderflowInt32();
	return new Operand(value, eOperandType::Int32);
}

IOperand const* OperandFactory::createFloat(std::string const& value) const
{
	std::stof(value);
	return new Operand(value, eOperandType::Float);
}

IOperand const* OperandFactory::createDouble(std::string const& value) const
{
	std::stod(value);
	return new Operand(value, eOperandType::Double);
}
