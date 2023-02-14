#include <iostream>
#include <string>
#include <vector>
#include <sstream>


#include "Expression.h"
#include "Parser.h"

int main() {
	Parser parser{} ;
	auto result = parser.Parse("0 AND 1 OR 31") ;
	std::cout << std::boolalpha << "Expression returns:" << result->Interpret() << '\n' ;
}
