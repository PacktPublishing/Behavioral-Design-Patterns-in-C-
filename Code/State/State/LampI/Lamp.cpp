#include "Lamp.h"

#include "ConsoleColors.h"


void Lamp::SwitchOn() {
	switch (m_State) {
	case State::OFF:
		system("cls");
		Console::Write(m_Image, Color::WHITE, true);
		std::cout << "Turned On\n";
		m_State = State::ON;
		break;
	case State::ON:
		std::cout << "Already On\n";
		break;
	}

}

void Lamp::SwitchOff() {
	switch (m_State) {
	case State::ON:
		system("cls");
		Console::Write(m_Image, Color::GRAY);
		std::cout << "Turned Off\n";
		m_State = State::OFF ;
		break;
	case State::OFF:
		std::cout << "Already turned Off\n";
		break;
	}

}
