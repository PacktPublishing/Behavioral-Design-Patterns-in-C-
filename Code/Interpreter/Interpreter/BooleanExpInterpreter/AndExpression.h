#pragma once
#include "Expression.h"
class AndExpression :
    public Expression
{
	ExpressionPtr m_pExpression1{} ;
	ExpressionPtr m_pExpression2{} ;

public:
	AndExpression(ExpressionPtr pExpression1, ExpressionPtr pExpression2);
	bool Interpret() override;
};

