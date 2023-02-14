#include "ConcreteHandler2.h"

#include <iostream>

void ConcreteHandler2::Set(bool canHandle) {
	m_CanHandle = canHandle ;
}

void ConcreteHandler2::HandleRequest() {
	if(m_CanHandle) {
		std::cout << "[ConcreteHandler2] Request handled\n" ;
	}else if(m_pNext){
		std::cout << "[ConcreteHandler2] Passing to next\n" ;
		m_pNext->HandleRequest() ;
	}else {
		std::cout << "[ConcreteHandler2] No handler\n" ;
	}
}
