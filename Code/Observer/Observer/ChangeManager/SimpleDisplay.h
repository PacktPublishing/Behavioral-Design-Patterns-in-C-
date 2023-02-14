#pragma once
#include "OnValueChanged.h"
class SimpleDisplay :
    public OnValueChanged
{

public:
	void Notify(Sensor *pSensor) override;
};

