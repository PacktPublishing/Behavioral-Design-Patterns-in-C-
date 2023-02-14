#include "Memento.h"

void Memento::SetState(const std::string& state) {
	m_State = state ;
}

const std::string& Memento::GetState() const {
	return m_State ;
}
