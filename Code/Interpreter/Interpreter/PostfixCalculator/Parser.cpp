#include "Parser.h"

#include <stack>
#include <sstream>



#include "Divide.h"
#include "Minus.h"
#include "Multiply.h"
#include "Number.h"
#include "Plus.h"
class Expression;


std::optional<int> Parser::ToInteger(const std::string& value) {
	try {
		return std::stoi(value) ;
	}
	catch (...) {
	}
	return std::nullopt ;
}

std::pair<Expression*, Expression*> Parser::GetOperands(std::stack<Expression*> &expression_stack) {
	auto rightExpression = expression_stack.top();
	expression_stack.pop() ;
	auto leftExpression = expression_stack.top();
	expression_stack.pop() ;
	return {leftExpression, rightExpression} ;
}

int Parser::Evaluate(const std::string& expression) {
	std::stack<Expression *> expression_stack{} ;
	Expression *pExpression{} ;
	std::stringstream expression_string{expression} ;
	std::string token{} ;
	int result{} ;

	while(expression_string >> token) {
		if(token == "+") {
			auto operands = GetOperands(expression_stack);
			pExpression = new Plus{operands.first, operands.second} ;
			result = pExpression->Interpret() ;
			expression_stack.push(new Number{result}) ;
		}else if(token == "-") {
			auto operands = GetOperands(expression_stack);
			pExpression = new Minus{operands.first, operands.second} ;
			result = pExpression->Interpret() ;
			expression_stack.push(new Number{result}) ;
		}else if(token == "*"){
			auto operands = GetOperands(expression_stack);
			pExpression = new Multiply{operands.first, operands.second} ;
			result = pExpression->Interpret() ;
			expression_stack.push(new Number{result}) ;
		}else if(token == "/"){
			auto operands = GetOperands(expression_stack);
			pExpression = new Divide{operands.first, operands.second} ;
			result = pExpression->Interpret() ;
			expression_stack.push(new Number{result}) ;
		}else if(auto number = ToInteger(token); number.has_value()) {
			expression_stack.push(new Number{number.value()}) ;
		}
	}
	expression_stack.pop() ;
	return result ;
}
