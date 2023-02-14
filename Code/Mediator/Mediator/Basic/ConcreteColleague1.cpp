#include "ConcreteColleague1.h"

#include <iostream>
#include "Mediator.h"
void ConcreteColleague1::SendMessageA() {
	std::cout << "[ConcreteColleague1] Sending message (A)\n" ;
	m_pMediator->OnInvoke(this) ;
}

void ConcreteColleague1::SendMessageB() {
	std::cout << "[ConcreteColleague1] Receiving message (B)\n" ;
}

std::string ConcreteColleague1::GetType() const {
	return "cc1" ;
}
