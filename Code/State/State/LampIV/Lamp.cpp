#include "Lamp.h"

#include <cstdlib>


#include "../LampI/ConsoleColors.h"


struct Lamp::LampImpl{
	void SwitchOn(Lamp *pLamp) {
		Console::Write(pLamp->m_Image, Color::WHITE) ;
	}
	void SwitchOff(Lamp *pLamp) {
		Console::Write(pLamp->m_Image, Color::GRAY) ;
	}
	void SwitchToYellow(Lamp *pLamp) {
		Console::Write(pLamp->m_Image, Color::YELLOW) ;
	}
} ;
Lamp::Lamp():m_pImpl{new LampImpl{}} {
	m_Table.AddEntry(
		std::make_pair("off_state", "SwitchOff"),
		std::make_pair(nullptr, "off_state")
	) ;
	m_Table.AddEntry(
		std::make_pair("off_state", "SwitchOn"),
		std::make_pair(std::bind(&LampImpl::SwitchOn, m_pImpl.get(), this), "on_state")
	) ;

	m_Table.AddEntry(
		std::make_pair("on_state", "SwitchOn"),
		std::make_pair(std::bind(&LampImpl::SwitchToYellow, m_pImpl.get(), this), "yellow_state")
	) ;

	m_Table.AddEntry(
		std::make_pair("on_state", "SwitchOff"),
		std::make_pair(std::bind(&LampImpl::SwitchOff, m_pImpl.get(), this), "off_state")
	) ;

	m_Table.AddEntry(
		std::make_pair("yellow_state", "SwitchOff"),
		std::make_pair(std::bind(&LampImpl::SwitchOff, m_pImpl.get(), this), "off_state")
	) ;

	m_Table.AddEntry(
		std::make_pair("yellow_state", "SwitchOn"),
		std::make_pair(std::bind(&LampImpl::SwitchOn, m_pImpl.get(), this), "on_state")
	) ;
}
Lamp::~Lamp() =default ;
void Lamp::SwitchOn() {
	system("cls") ;
	m_CurrentState = m_Table.DoTransition(m_CurrentState, "SwitchOn") ;
}

void Lamp::SwitchOff() {
	system("cls") ;
	m_CurrentState = m_Table.DoTransition(m_CurrentState, "SwitchOff") ;
}
