#pragma once
#include "State.h"
class YellowState :
    public State
{
public:
	void SwitchOn(Lamp* pLamp) override;
	void SwitchOff(Lamp* pLamp) override;
};

