#pragma once

#include "Operand.hpp"

class Double : public Operand
{
	Double(double d);
	virtual std::string const& toString(void) const;
};
