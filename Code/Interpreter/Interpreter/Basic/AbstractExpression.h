#pragma once
#include <string>

class AbstractExpression
{
public:
	virtual void Interpret(const std::string &context) = 0 ;
	virtual ~AbstractExpression()=default ;
};

