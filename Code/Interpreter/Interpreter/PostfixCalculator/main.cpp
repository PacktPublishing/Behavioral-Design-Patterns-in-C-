#include <iostream>

#include "Parser.h"

int main() {
	Parser parser{} ;
	/*
	 * 3 + 2 - 9	-> 3 2 + 9 -
	 * 81 - 56 + 2	-> 81 56 - 2 +
	 * 5 + 6 * 2	-> 5 6 2 * +
	 * 3 * 2 + 9 / 3	-> 3 2 * 9 3 / + 
	 */
	std::cout << parser.Evaluate("5 6 2 * +") << '\n' ;
	std::cout << parser.Evaluate("3 2 * 9 3 / +") << '\n' ;
}
