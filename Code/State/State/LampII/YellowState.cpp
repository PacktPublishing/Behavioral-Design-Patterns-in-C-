#include "YellowState.h"

#include "../LampI/ConsoleColors.h"
#include "Lamp.h"
#include "StateFactory.h"

void YellowState::SwitchOn(Lamp* pLamp) {
	system("cls");
	Console::Write(pLamp->GetImage(), Color::WHITE, true);
	std::cout << "Setting to white light\n";
	pLamp->SetState(StateFactory::GetState("on_state"));
}

void YellowState::SwitchOff(Lamp* pLamp) {
	system("cls");
	Console::Write(pLamp->GetImage(), Color::GRAY, true);
	std::cout << "Turned Off\n";
	pLamp->SetState(StateFactory::GetState("off_state"));
}
