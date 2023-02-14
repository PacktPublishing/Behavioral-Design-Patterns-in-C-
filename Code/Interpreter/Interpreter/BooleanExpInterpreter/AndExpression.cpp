#include "AndExpression.h"

AndExpression::AndExpression(ExpressionPtr pExpression1, ExpressionPtr pExpression2): m_pExpression1{pExpression1},
	m_pExpression2{pExpression2} {
}

bool AndExpression::Interpret() {
	return m_pExpression1->Interpret() && m_pExpression2->Interpret() ;
}
