#pragma once
#include "AbstractExpression.h"
class NonTerminalExpression :
    public AbstractExpression
{
	AbstractExpression *m_pExp1{} ;
	AbstractExpression *m_pExp2{} ;

public:
	NonTerminalExpression(AbstractExpression* pExp1, AbstractExpression* pExp2);

	void Interpret(const std::string& context) override;
};

