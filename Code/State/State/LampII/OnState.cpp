#include "OnState.h"

#include <iostream>
#include "Lamp.h"
#include "StateFactory.h"
#include "../LampI/ConsoleColors.h"

void OnState::SwitchOn(Lamp* pLamp) {
	system("cls");
	Console::Write(pLamp->GetImage(), Color::YELLOW);
	std::cout << "Switched to Yellow color\n";
	pLamp->SetState(StateFactory::GetState("yellow_state"));
}

void OnState::SwitchOff(Lamp* pLamp) {
	system("cls");
	Console::Write(pLamp->GetImage(), Color::GRAY);
	std::cout << "Turned Off\n";
	pLamp->SetState(StateFactory::GetState("off_state"));
}
