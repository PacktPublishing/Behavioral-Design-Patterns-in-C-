#pragma once
#include <string>
#include <vector>

#include "Expression.h"


class Parser
{
	using TokenizedStream = std::vector<std::string> ;
	TokenizedStream Lexer(const std::string &context) ;
public:
	ExpressionPtr Parse(const std::string & expression);
};

