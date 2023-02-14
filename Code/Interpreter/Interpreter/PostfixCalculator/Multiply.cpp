#include "Multiply.h"

Multiply::Multiply(Expression* pExpression1, Expression* pExpression2): m_pExpression1{pExpression1},
                                                                        m_pExpression2{pExpression2} {
}

int Multiply::Interpret() {
	return m_pExpression1->Interpret() * m_pExpression2->Interpret() ;
}
