#pragma once
#include "AbstractExpression.h"
class TerminalExpression :
    public AbstractExpression
{
	std::string m_Symbol{} ;

public:
	explicit TerminalExpression(const std::string& symbol);

	void Interpret(const std::string& context) override;
};

