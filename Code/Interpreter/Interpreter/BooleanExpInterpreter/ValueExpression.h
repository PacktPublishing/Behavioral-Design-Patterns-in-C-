#pragma once
#include <string>

#include "Expression.h"
class ValueExpression :
    public Expression
{
	std::string m_Context{} ;

public:
	explicit ValueExpression(const std::string& context);
	bool Interpret() override;
};

