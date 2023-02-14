#include "Person.h"

#include <iostream>

#include "Server.h"
void Person::Send(const std::string& to, const std::string& message) {
	m_pServer->SendMessage(GetName(), to, message) ;
}

void Person::Receive(const std::string& from, const std::string& message) {
	std::cout << GetName()
		<< " received message: "
		<< "[" << from << "]"
		<< message
		<< '\n' ;
}

