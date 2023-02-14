#include "Parser.h"
#include <sstream>


#include "AndExpression.h"
#include "Expression.h"
#include "ORExpression.h"
#include "ValueExpression.h"

Parser::TokenizedStream Parser::Lexer(const std::string& context) {
	std::istringstream tokens_buffer{context} ;
	std::string token{} ;
	TokenizedStream tokenizedStream{} ;
	while(tokens_buffer >> token) {
		tokenizedStream.push_back(token) ;
	}
	return tokenizedStream ;
}

ExpressionPtr Parser::Parse(const std::string & expression) {
	auto tokenizedStream = Lexer(expression) ;
	ExpressionPtr m_pResult{} ;
	std::string token{} ;
	for(size_t i = 0 ; i < tokenizedStream.size() ;++i) {
		if(tokenizedStream[i] == "AND") {
			token = tokenizedStream[++i] ;
			m_pResult = std::make_shared<AndExpression>(
				m_pResult, 
				std::make_shared<ValueExpression>(token)) ;
		}else if(tokenizedStream[i] == "OR") {
			token = tokenizedStream[++i] ;
			m_pResult = std::make_shared<ORExpression>(
				m_pResult, 
				std::make_shared<ValueExpression>(token)) ;
		}
		else {
			m_pResult = std::make_shared<ValueExpression>(tokenizedStream[i]) ;
		}
	}
	return m_pResult ;
}
