#include "Context.h"

#include <iostream>

#include "Strategy.h"
void Context::ContextInterface() {
	if(m_pStrategy) {
		m_pStrategy->AlgorithInterface() ;
	}else {
		std::cout << "Default behavior\n" ;
	}
}

void Context::SetStrategy(Strategy* p) {
	m_pStrategy = p ;
}
