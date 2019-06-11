#include "..\include\Exceptions.hpp"

OverflowInt8::OverflowInt8() : std::overflow_error("Int8 overflow")
{
}

OverflowInt16::OverflowInt16() : std::overflow_error("Int16 overflow")
{
}

OverflowInt32::OverflowInt32() : std::overflow_error("Int32 overflow")
{
}

OverflowFloat::OverflowFloat() : std::overflow_error("Float overflow")
{
}

OverflowDouble::OverflowDouble() : std::overflow_error("Double overflow")
{
}

UnderflowInt8::UnderflowInt8() : std::underflow_error("Int8 underflow")
{
}

UnderflowInt16::UnderflowInt16() : std::underflow_error("Int16 underflow")
{
}

UnderflowInt32::UnderflowInt32() : std::underflow_error("Int32 underflow")
{
}

UnderflowFloat::UnderflowFloat() : std::underflow_error("Float underflow")
{
}

UnderflowDouble::UnderflowDouble() : std::underflow_error("Double underflow")
{
}

DivisionByZero::DivisionByZero() : std::domain_error("Division by zero")
{
}

ModuloByZero::ModuloByZero() : std::domain_error("Modulo by zero")
{
}

LexicalError::LexicalError(std::string str) : std::domain_error("Invalid line: " + str)
{
}

UnknownInstruction::UnknownInstruction(std::string str) : std::domain_error("Unknown Instruction: " + str)
{
}

PopOnEmptyStack::PopOnEmptyStack() : std::logic_error("Poping empty stack")
{
}

AssertFailed::AssertFailed() : std::logic_error("Assert Failed")
{
}

NotEnoughStackElement::NotEnoughStackElement() : std::logic_error("Less than two stack element")
{
}
