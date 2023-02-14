#pragma once
#include "Expression.h"
class Minus :
	public Expression
{
	Expression* m_pExpression1;
	Expression* m_pExpression2;

public:
	Minus(Expression* pExpression1, Expression* pExpression2);
	int Interpret() override;
};

