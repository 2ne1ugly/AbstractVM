#pragma once

#include <string>


enum class eSeperatorType
{
	Error = -1,
	None = 0,
	Ws = 1,
	Nl = 2,
	Comment = 3
};

enum class eOperandType
{
	Error = -1,
	None = 0,
	Int8 = 4,
	Int16 = 5,
	Int32 = 6,
	Float = 7,
	Double = 8
};

enum class eCommandType
{
	Error = -1,
	None = 0,
	Exit = 16,
	Push = 17,
	Pop = 18,
	Dump = 19,
	Assert = 20,
	Add = 21,
	Sub = 22,
	Mul = 23,
	Div = 24,
	Mod = 25,
	Print = 26,
	EndStream = 27
};
