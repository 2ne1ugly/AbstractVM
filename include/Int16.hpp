#pragma once

#include "Operand.hpp"

class Int16 : public Operand
{
	Int16(short s);
	virtual std::string const& toString(void) const;
};
