#include "ConcreteColleague2.h"

#include <iostream>
#include "Mediator.h"
void ConcreteColleague2::SendMessageA() {
	std::cout << "[ConcreteColleague2] Received message (A)\n" ;
}

void ConcreteColleague2::SendMessageB() {
	std::cout << "[ConcreteColleague2] Sending message (B)\n" ;
	m_pMediator->OnInvoke(this) ;
}

std::string ConcreteColleague2::GetType() const {
	return "cc2" ;
}
