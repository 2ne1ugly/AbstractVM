#include "AvmParser.hpp"
#include <iostream>
#include "Operand.hpp"

void AvmParser::feedToken(int op, std::string str)
{
	// -1, 0
	if (op <= 0)
	{
		_errorMode = true;
		_buffer.append(str);
		return ;
	}
	// 1, 2, 3
	if (op == (int)eSeperatorType::Comment ||
		op == (int)eSeperatorType::Nl ||
		op == (int)eSeperatorType::Ws)
	{
		if (!_buffer.empty())
			errorBuffer();
		if (op == (int)eSeperatorType::Nl)
		{
			_lineNumber++;
			_commandExecuted = false;
		}
		if (_prevCommand != eCommandType::None)
			_separated = true;
		return ;
	}
	if (!_errorMode && _commandExecuted)
	{
		_errorMode = true;
		_buffer.append(str);
		return ;
	}
	//4, 5, 6, 7, 8
	if (op >= (int)eOperandType::Int8 && op <= (int)eOperandType::Double)
	{
		if (!_separated || _prevCommand == eCommandType::None)
		{
			_errorMode = true;
			_buffer.append(str);
			return ;
		}
		_separated = false;
		_commandExecuted = true;
		if (_errorMode == true)
		{
			_prevCommand = eCommandType::None;
			return ;
		}
		int cl = 0;
		switch ((eOperandType)op) {
		case eOperandType::Int8:
			cl = 5;
			break;
		case eOperandType::Int16:
		case eOperandType::Int32:
		case eOperandType::Float:
			cl = 6;
			break;
		case eOperandType::Double:
			cl = 7;
			break;
		default:
			break;
		}
		int l = str.length() - cl - 1;
		std::string number(str, cl, l);
		OperandFactory of;
		try {
			if (_prevCommand == eCommandType::Push)
				_stack.push_back(of.createOperand((eOperandType)op, number));
			else if (_prevCommand == eCommandType::Assert)
			{
				if (_stack.size() == 0)
				{
					_errorMode = true;
					std::cout << _lineNumber << ": assert on empty stack(" << str << ")" << std::endl;
				}
				else if (_stack.back()->toString() != number)
				{
					_errorMode = true;
					std::cout << _lineNumber << ": assert failed(" << str << ", " << _stack.back()->toString() << ")" << std::endl;
				}
			}
		} catch (std::exception &e) {
			_errorMode = true;
			std::cout << _lineNumber << ": error on (" << str << "). message was: " << e.what() << std::endl;
		}
		_prevCommand = eCommandType::None;
		return ;
	}
	IOperand const* rhs;
	IOperand const* lhs;
	IOperand const* val; 
	switch ((eCommandType)op) {
	case eCommandType::Exit:
	case eCommandType::EndStream:
		if (op == (int)eCommandType::Exit && _isStdin)
		{
			_errorMode = true;
			std::cout << _lineNumber << ": incorrect command for stdin" << std::endl;
		}
		else if (op == (int)eCommandType::EndStream && !_isStdin)
		{
			_errorMode = true;
			std::cout << _lineNumber << ": incorrect command for file read" << std::endl;
		}
		_finished = true;
		break;
	case eCommandType::Dump:
		if (!_errorMode)
			for (int i = _stack.size() - 1; i >= 0; i--)
				std::cout << _stack[i]->toString() << std::endl;
		break;
	case eCommandType::Assert:
	case eCommandType::Push:
		if (_prevCommand != eCommandType::None)
		{
			_errorMode = true;
			std::cout << _lineNumber << ": _prevCommand not ended" << std::endl;
		}
		_prevCommand = (eCommandType)op;
		break;
	case eCommandType::Add:
	case eCommandType::Sub:
	case eCommandType::Mul:
	case eCommandType::Div:
	case eCommandType::Mod:
		if (_errorMode)
			return ;
		if (_stack.size() < 2)
		{
			_errorMode = true;
			std::cout << _lineNumber << ": calculation on stack smaller than 2 (" << str << ")" << std::endl;
			return ;
		}
		rhs = _stack.back();
		_stack.pop_back();
		lhs = _stack.back();
		_stack.pop_back();
		try {
			switch ((eCommandType)op) {
			case eCommandType::Add:
				_stack.push_back(*lhs + *rhs);
				break;
			case eCommandType::Sub:
				_stack.push_back(*lhs - *rhs);
				break;
			case eCommandType::Mul:
				_stack.push_back(*lhs * *rhs);
				break;
			case eCommandType::Div:
				_stack.push_back(*lhs / *rhs);
				break;
			case eCommandType::Mod:
				_stack.push_back(*lhs % *rhs);
				break;
			default:
				break;
			}
		} catch (std::exception &e) {
			_errorMode = true;
			std::cout << _lineNumber << ": error on (" << str << "). message was: " << e.what() << std::endl;
		}
		delete rhs;
		delete lhs;
		break;
	case eCommandType::Print:
		if (_errorMode)
			return ;
		if (_stack.size() == 0)
		{
			_errorMode = true;
			std::cout << _lineNumber << ": print on empty stack" << std::endl;
			return ;
		}
		if (_stack.back()->getType() != eOperandType::Int8)
		{
			_errorMode = true;
			std::cout << _lineNumber << ": print on empty stack" << std::endl;
			return ;
		}
		std::cout << (char)std::stoi(_stack.back()->toString());
		break;
	case eCommandType::Pop:
		if (_errorMode)
			return ;
		if (_stack.size() == 0)
		{
			_errorMode = true;
			std::cout << _lineNumber << ": print on empty stack" << std::endl;
			return ;
		}
		val = _stack.back();
		_stack.pop_back();
		delete val;
		break;
	default:
		break;
	}
}
bool AvmParser::isFinished()
{
	return _finished;
}

void AvmParser::endParse()
{
	if (!_buffer.empty())
		errorBuffer();
	if (!_finished && !_errorMode)
		std::cout << _lineNumber << ": no ending command" << std::endl; 
}

void AvmParser::errorBuffer()
{
	std::cout << _lineNumber << ": incorrect or unknown token("  << _buffer << ")" << std::endl;
	_buffer.clear();
}

AvmParser::AvmParser(bool isStdin)
{
	_isStdin = isStdin;
}
