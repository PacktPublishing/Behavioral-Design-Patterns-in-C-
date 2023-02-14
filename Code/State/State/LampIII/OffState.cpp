#include "OffState.h"

#include <iostream>

#include "../LampI/ConsoleColors.h"
#include "Lamp.h"
#include "StateFactory.h"

void OffState::SwitchOn(Lamp* pLamp) {
	Console::Write(pLamp->GetImage(), Color::WHITE, true);
	std::cout << "Turned On\n";
}

void OffState::SwitchOff(Lamp* pLamp) {
	std::cout << "Already off\n";
}
