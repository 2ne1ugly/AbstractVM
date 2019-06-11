#include "Int16.hpp"

Int16::Int16(short s)
{
	_value = reinterpret_cast<unsigned long long>(s);
	_type = eOperandType::Int16;
}

std::string const& Int16::toString(void) const
{
	return std::to_string(reinterpret_cast<int>(_value);
}
