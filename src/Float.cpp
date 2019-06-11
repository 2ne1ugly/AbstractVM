#include "Float.hpp"

Float::Float(float f)
{
	_value = reinterpret_cast<unsigned long long>(f);
	_type = eOperandType::Float;
}

std::string const& Float::toString(void) const
{
	return std::to_string(reinterpret_cast<float>(_value);
}
