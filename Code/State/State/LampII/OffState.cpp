#include "OffState.h"

#include <iostream>

#include "../LampI/ConsoleColors.h"
#include "Lamp.h"
#include "StateFactory.h"

void OffState::SwitchOn(Lamp* pLamp) {
	system("cls");
		Console::Write(pLamp->GetImage(), Color::WHITE, true);
		std::cout << "Turned On\n";
	pLamp->SetState(StateFactory::GetState("on_state")) ;
}

void OffState::SwitchOff(Lamp* pLamp) {
	std::cout << "Already off\n" ;
}
