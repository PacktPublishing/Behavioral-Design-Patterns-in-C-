#pragma once
#include "OnValueChanged.h"
class Display :
    public OnValueChanged
{

public:
	void Notify(Sensor *pSubject) override;
};

