#pragma once
#include "OnValueChanged.h"
class Display :
    public OnValueChanged
{

public:
	void Notify(float value) override;
};

