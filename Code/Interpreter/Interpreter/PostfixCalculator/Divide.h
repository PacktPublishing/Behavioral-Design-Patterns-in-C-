#pragma once
#include "Expression.h"
class Divide :
	public Expression
{
	Expression* m_pExpression1;
	Expression* m_pExpression2;
public:
	Divide(Expression* pExpression1, Expression* pExpression2);

	int Interpret() override;
};

