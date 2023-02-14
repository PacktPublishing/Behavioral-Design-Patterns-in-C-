#include "Caretaker.h"

void Caretaker::AddMemento(Memento m) {
	m_States.push_back(m) ;
}

Memento Caretaker::Restore(size_t index) {
	return m_States[index] ;
}
