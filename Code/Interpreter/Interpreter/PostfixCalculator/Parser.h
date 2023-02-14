#pragma once
#include <string>
#include <optional>
#include <stack>


#include "Expression.h"

class Parser
{
	std::optional<int> ToInteger(const std::string &value) ;
	std::pair<Expression*, Expression*> GetOperands(std::stack<Expression*> &expression_stack);
public:
	int Evaluate(const std::string & expression) ;
};

