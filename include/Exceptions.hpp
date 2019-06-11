#pragma once

#include <stdexcept>

class OverflowInt8 : public	std::overflow_error
{
public:
	OverflowInt8();
}

class OverflowInt16 : public std::overflow_error
{
public:
	OverflowInt16();
}

class OverflowInt32 : public std::overflow_error
{
public:
	OverflowInt32();
}

class OverflowFloat : public std::overflow_error
{
public:
	OverflowFloat();
}

class OverflowDouble : public std::overflow_error
{
public:
	OverflowDouble();
}

class UnderflowInt8 : public std::underflow_error
{
public:
	UnderflowInt8();
}

class UnderflowInt16 : public std::underflow_error
{
public:
	UnderflowInt16();
}

class UnderflowInt32 : public std::underflow_error
{
public:
	UnderflowInt32();
}

class UnderflowFloat : public std::underflow_error
{
public:
	UnderflowFloat();
}

class UnderflowDouble : public std::underflow_error
{
public:
	UnderflowDouble();
}

class DivisionByZero : public std::domain_error
{
public:
	DivisionByZero();
};

class ModuloByZero : public std::domain_error
{
public:
	ModuloByZero();
};

class LexicalError : public std::invalid_argument
{
public:
	LexicalError(std::string str);
};

class UnknownInstruction : public std::invalid_argument
{
public:
	UnknownInstruction(std::string str);
};

class PopOnEmptyStack : public std::logic_error
{
public:
	PopOnEmptyStack();
};

class AssertFailed : public std::logic_error
{
public:
	AssertFailed();
};

class NotEnoughStackElement : public std::logic_error
{
public:
	NotEnoughStackElement();
};
