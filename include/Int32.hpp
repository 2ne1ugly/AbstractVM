#pragma once

#include "Operand.hpp"

class Int32 : public Operand
{
	Int32(int i);
	virtual std::string const& toString(void) const;
};
