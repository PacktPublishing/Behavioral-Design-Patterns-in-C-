#pragma once
#include "OnValueChanged.h"
class Recorder :
    public OnValueChanged
{

public:
	void Notify(Sensor *pSensor) override;
};

