#pragma once
#include "State.h"
class OnState :
    public State
{

public:
	void SwitchOn(Lamp* pLamp) override;
	void SwitchOff(Lamp* pLamp) override;
};

