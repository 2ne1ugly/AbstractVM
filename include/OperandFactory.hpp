#pragma once

#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"

class OperandFactory
{
	IOperand const* createOperand(eOperandType type, std::string const& value) const;	IOperand const* createInt8(std::string const& value) const;
	IOperand const* createInt16(std::string const& value) const;
	IOperand const* createInt32(std::string const& value) const;
	IOperand const* createFloat(std::string const& value) const;
	IOperand const* createDouble(std::string const& value) const;
};