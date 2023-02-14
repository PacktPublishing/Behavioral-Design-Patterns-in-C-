#include "YellowState.h"

#include "../LampI/ConsoleColors.h"
#include "Lamp.h"
#include "StateFactory.h"

void YellowState::SwitchOn(Lamp* pLamp) {
	Console::Write(pLamp->GetImage(), Color::WHITE, true);
	std::cout << "Setting to white light\n";
}

void YellowState::SwitchOff(Lamp* pLamp) {
	Console::Write(pLamp->GetImage(), Color::GRAY, true);
	std::cout << "Turned Off\n";
}
