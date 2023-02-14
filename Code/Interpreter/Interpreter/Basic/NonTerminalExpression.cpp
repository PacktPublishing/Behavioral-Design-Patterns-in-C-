#include "NonTerminalExpression.h"

#include <iostream>

NonTerminalExpression::NonTerminalExpression(AbstractExpression* pExp1, AbstractExpression* pExp2): m_pExp1{pExp1},
                                                                                                    m_pExp2{pExp2} {
}
//1+2
void NonTerminalExpression::Interpret(const std::string& context) {
	std::cout << "[NonTerminalExpression]\n" ;
	m_pExp1->Interpret(context) ;
	std::cout << context ;
	m_pExp2->Interpret(context) ;
}
