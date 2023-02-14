#include "MainWindow.h"

#include <iostream>

MainWindow::MainWindow() {
	m_Text.assign(R"(
In software engineering, a software design pattern is a general, reusable solution to a commonly occurring problem within a given context in software design. It is not a finished design that can be transformed directly into source or machine code. Rather, it is a description or template for how to solve a problem that can be used in many different situations. Design patterns are formalized best practices that the programmer can use to solve common problems when designing an application or system.

Object-oriented design patterns typically show relationships and interactions between classes or objects, without specifying the final application classes or objects that are involved. Patterns that imply mutable state may be unsuited for functional programming languages, some patterns can be rendered unnecessary in languages that have built-in support for solving the problem they are trying to solve, and object-oriented patterns are not necessarily suitable for non-object-oriented languages.

Design patterns may be viewed as a structured approach to computer programming intermediate between the levels of a programming paradigm and a concrete algorithm.
)") ;
	m_Text.assign("Hello world from Java & C++. Hello there. How are you?") ;
}

void MainWindow::ExecuteFind(const std::string& text) {
	if(text.empty()) {
		return ;
	}
	size_t position{} ;
	size_t count{} ;
	while((position = m_Text.find(text, position)) != std::string::npos) {
		std::cout << "Found at index:" << position << '\n' ;
		position += text.size() ;
		++count ;
	}
	if(count != 0) {
		std::cout << "Total occurrences:" << count << '\n' ;
	}else {
		std::cout << "Not found!\n" ;
	}
}
