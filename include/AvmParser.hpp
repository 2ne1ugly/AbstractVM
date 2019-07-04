#pragma once

#include "abstractVM.h"
#include <string>
#include "IOperand.hpp"
#include <vector>

class AvmParser
{
public:
	virtual ~AvmParser() {};
	AvmParser() = delete;
	AvmParser(bool isStdin);
	AvmParser(const AvmParser &) = delete;
	AvmParser &operator=(const AvmParser &) = delete;

	void feedToken(int opp, std::string);
	void endParse();
	void errorBuffer();
	bool isFinished();
private:
	bool							_errorMode = false;
	std::string						_buffer;
	int								_lineNumber = 1;
	bool							_commandExecuted = false;
	bool							_finished = false;
	bool							_separated = false;
	eCommandType					_prevCommand = eCommandType::None;
	std::vector<IOperand const*>	_stack;
	bool							_isStdin;
};
