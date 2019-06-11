#pragma once

#include "Operand.hpp"

class Int8 : public Operand
{
	Int8(char c);
	virtual std::string const& toString(void) const;
};
