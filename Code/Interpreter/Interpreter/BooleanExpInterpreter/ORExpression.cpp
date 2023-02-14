#include "ORExpression.h"

ORExpression::ORExpression(const ExpressionPtr& pExpression1, const ExpressionPtr& pExpression2):
	m_pExpression1{pExpression1},
	m_pExpression2{pExpression2} {
}

bool ORExpression::Interpret() {
	return m_pExpression1->Interpret() || m_pExpression2->Interpret() ;
}
