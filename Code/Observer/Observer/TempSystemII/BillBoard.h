#pragma once
#include "OnValueChanged.h"
class BillBoard :
    public OnValueChanged
{

public:
	void Notify(float value) override;
};

