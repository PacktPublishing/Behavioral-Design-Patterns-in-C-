#pragma once
#include "OnValueChanged.h"
class SimpleDisplay :
    public OnValueChanged
{

public:
	void Notify(float value) override;
};

