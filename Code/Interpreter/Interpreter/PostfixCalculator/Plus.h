#pragma once
#include "Expression.h"
class Plus :
    public Expression
{
	Expression *m_pExpression1 ;
	Expression *m_pExpression2 ;

public:
	Plus(Expression* pExpression1, Expression* pExpression2);
	int Interpret() override;
};

