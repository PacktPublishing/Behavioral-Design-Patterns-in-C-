#pragma once
#include "State.h"
class ConcreteStateB :
    public State
{

public:
	State* Handle() override;
};

