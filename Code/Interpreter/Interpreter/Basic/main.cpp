#include <string>

#include "NonTerminalExpression.h"
#include "TerminalExpression.h"

void Parse(const std::string &context) {
	NonTerminalExpression *expression = new NonTerminalExpression{
		new TerminalExpression{context.substr(0, 1)},
		new TerminalExpression{context.substr(2, 1)},
	} ;
	expression->Interpret(context.substr(1,1)) ;
}
int main() {
	Parse("3+8") ;
}
