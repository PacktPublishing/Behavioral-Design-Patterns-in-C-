#include "TerminalExpression.h"

#include <iostream>

TerminalExpression::TerminalExpression(const std::string& symbol): m_Symbol{symbol} {
}

void TerminalExpression::Interpret(const std::string& context) {
	std::cout << '`' << m_Symbol << '`' ;
}
