#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using TokenizedStream = std::vector<std::string> ;

bool ToBool(const std::string &token) {
	return std::stoi(token) != 0 ;
}

TokenizedStream Lexer(const std::string &context) {
	std::istringstream tokens_buffer{context} ;
	std::string token{} ;
	TokenizedStream tokenizedStream{} ;
	while(tokens_buffer >> token) {
		tokenizedStream.push_back(token) ;
	}
	return tokenizedStream ;
}
bool Parse(const TokenizedStream & tokenizedStream) {
	bool result{} ;
	std::string token{} ;
	for(size_t i = 0 ; i < tokenizedStream.size() ;++i) {
		if(tokenizedStream[i] == "AND") {
			token = tokenizedStream[++i] ;
			result = result && ToBool(token) ;
		}else {
			result = ToBool(tokenizedStream[i]) ;
		}
	}
	return result ;
}
int main() {
	auto result = Parse(Lexer("0 AND 1 AND 31")) ;
	std::cout << std::boolalpha << "Expression returns:" << result << '\n' ;
}
