#include "Originator.h"

#include <iostream>

Memento Originator::CreateMemento() const {
	return {m_State} ;
}

void Originator::SetMemento(Memento memento) {
	m_State = memento.GetState() ;
}

void Originator::Input() {
	std::getline(std::cin, m_State) ;
}

void Originator::PrintState() {
	std::cout << "\n----State: " << m_State << '\n' ;
}
