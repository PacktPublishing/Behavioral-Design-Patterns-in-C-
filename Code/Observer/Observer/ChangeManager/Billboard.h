#pragma once
#include "OnValueChanged.h"
class Billboard :
    public OnValueChanged
{

public:
	void Notify(Sensor *pSensor) override;
};

