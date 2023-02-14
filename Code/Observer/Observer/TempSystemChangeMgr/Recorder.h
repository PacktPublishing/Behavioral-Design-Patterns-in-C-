#pragma once
#include "OnValueChanged.h"
class Recorder :
    public OnValueChanged
{
	void Notify(Sensor *pSubject) override;
};

