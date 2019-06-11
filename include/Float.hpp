#pragma once

#include "Operand.hpp"

class Float : public Operand
{
	Float(float f);
	virtual std::string const& toString(void) const;
};
