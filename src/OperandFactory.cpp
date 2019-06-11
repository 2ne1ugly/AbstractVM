#include "OperandFactory.hpp"
#include "Exceptions.hpp"
#include <limits>

IOperand const* OperandFactory::createOperand(eOperandType type, std::string const& value) const
{
	switch (type)
	{
	case Int8:
		return createInt8(value);
		break;
	case Int16:
		return createInt16(value);
		break;
	case Int32:
		return createInt32(value);
		break;
	case Float:
		return createFloat(value);
		break;
	case Double:
		return createDouble(value);
		break;
	}
	return nullptr;
}

IOperand const* OperandFactory::createInt8(std::string const& value) const
{
	long long test = std::stoll(value);
	if (test > std::numeric_limits<char>.max())
		throw OverflowInt8();
	if (test < std::numeric_limits<char>.lowest())
		throw UnderflowInt8();
	return new Int8(std::stoi(value));
}

IOperand const* OperandFactory::createInt16(std::string const& value) const
{
	long long test = std::stoll(value);
	if (test > std::numeric_limits<short>.max())
		throw OverflowInt16();
	if (test < std::numeric_limits<short>.lowest())
		throw UnderflowInt16();
	return new Int16(std::stoi(value));
}

IOperand const* OperandFactory::createInt32(std::string const& value) const
{
	long long test = std::stoll(value);
	if (test > std::numeric_limits<int>.max())
		throw OverflowInt32();
	if (test < std::numeric_limits<int>.lowest())
		throw UnderflowInt32();
	return new Int32(std::stoi(value));
}

IOperand const* OperandFactory::createFloat(std::string const& value) const
{
	long long double test = std::stold(value);
	if (test > std::numeric_limits<float>.max())
		throw OverflowFloat();
	if (test < std::numeric_limits<float>.lowest())
		throw UnderflowFloat();
	return new Float(std::stof(value));
}

IOperand const* OperandFactory::createDouble(std::string const& value) const
{
	long long double test = std::stold(value);
	if (test > std::numeric_limits<double>.max())
		throw OverflowDouble();
	if (test < std::numeric_limits<double>.lowest())
		throw UnderflowDouble();
	return new Double(std::stod(value));
}
