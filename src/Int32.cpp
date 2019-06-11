#include "Int32.hpp"

Int32::Int32(int i)
{
	_value = reinterpret_cast<unsigned long long>(c);
	_type = eOperandType::Int32;
}

std::string const& Int32::toString(void) const
{
	return std::to_string(reinterpret_cast<int>(_value);
}
