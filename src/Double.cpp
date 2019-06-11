#include "Double.hpp"

Double::Double(double d)
{
	_value = reinterpret_cast<unsigned long long>(s);
	_type = eOperandType::Double;
}

std::string const& Double::toString(void) const
{
	return std::to_string(reinterpret_cast<double>(_value);
}
