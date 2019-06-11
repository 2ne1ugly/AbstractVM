#include "Int8.hpp"

Int8::Int8(char c)
{
	_value = reinterpret_cast<unsigned long long>(c);
	_type = eOperandType::Int8;
}

std::string const& Int8::toString(void) const;
{
	return std::to_string(reinterpret_cast<int>(_value);
}
