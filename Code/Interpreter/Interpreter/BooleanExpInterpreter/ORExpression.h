#pragma once
#include "Expression.h"
class ORExpression :
    public Expression
{
	ExpressionPtr m_pExpression1{} ;
	ExpressionPtr m_pExpression2{} ;

public:
	ORExpression(const ExpressionPtr& pExpression1, const ExpressionPtr& pExpression2);
	bool Interpret() override;
};

