#include "abstractVM.h"
#include "FlexLexer.h"
#include "AvmParser.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
int main(int argc, char **argv)
{
	(void)argc;

	FlexLexer* lexer = new yyFlexLexer();
	AvmParser* parser;
	if (argc == 1)
	{
		parser = new AvmParser(true);
	}
	else
	{
		parser = new AvmParser(false);
		std::ifstream *inputFile = new std::ifstream(argv[1]);
		if (!*inputFile)
		{
			std::cout << "file open failed" << std::endl;
			return (0);
		}
		lexer->switch_streams(inputFile);
	}
	int num;
	while ((num = lexer->yylex()))
	{
		parser->feedToken(num, lexer->YYText());
		if (parser->isFinished())
			break;
	}
	parser->endParse();
	return (0);
}
