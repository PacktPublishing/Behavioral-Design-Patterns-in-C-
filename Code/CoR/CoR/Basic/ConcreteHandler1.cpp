#include "ConcreteHandler1.h"

#include <iostream>

void ConcreteHandler1::Set(bool canHandle) {
	m_CanHandle = canHandle ;
}

void ConcreteHandler1::HandleRequest() {
	if(m_CanHandle) {
		std::cout << "[ConcreteHandler1] Request handled\n" ;
	}else if(m_pNext){
		std::cout << "[ConcreteHandler1] Passing to next\n" ;
		m_pNext->HandleRequest() ;
	}else {
		std::cout << "[ConcreteHandler1] No handler\n" ;
	}
}
