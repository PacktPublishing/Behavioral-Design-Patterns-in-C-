#include "ConcreteSubject.h"

const std::string& ConcreteSubject::GetState() const {
	return m_SubjectState ;
}

void ConcreteSubject::SetState(std::string state) {
	m_SubjectState = state ;
	Notify() ;
}
