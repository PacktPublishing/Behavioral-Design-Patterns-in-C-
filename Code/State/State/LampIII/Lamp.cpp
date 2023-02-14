#include "Lamp.h"

#include <cstdlib>


#include "OffState.h"

Lamp::Lamp() {
	m_pState = m_Table.GetDefaultState() ;
}

Lamp::~Lamp() {
}

const char* Lamp::GetImage() const {
	return m_Image ;
}

void Lamp::SwitchOn() {
	system("cls") ;
	m_pState->SwitchOn(this) ;
	m_pState = m_Table.DoTransition(m_pState, "SwitchOn") ;
}

void Lamp::SwitchOff() {
	system("cls") ;
	m_pState->SwitchOff(this) ;
	m_pState = m_Table.DoTransition(m_pState, "SwitchOff") ;
}

void Lamp::SetState(State* pState) {
	m_pState = pState ;
}
