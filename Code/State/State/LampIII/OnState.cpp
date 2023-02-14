#include "OnState.h"

#include <iostream>
#include "Lamp.h"
#include "StateFactory.h"
#include "../LampI/ConsoleColors.h"

void OnState::SwitchOn(Lamp* pLamp) {
	Console::Write(pLamp->GetImage(), Color::YELLOW);
}

void OnState::SwitchOff(Lamp* pLamp) {
	Console::Write(pLamp->GetImage(), Color::GRAY);
	std::cout << "Turned Off\n";
}
