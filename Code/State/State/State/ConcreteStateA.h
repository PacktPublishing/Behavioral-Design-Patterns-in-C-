#pragma once
#include "State.h"
class ConcreteStateA :
    public State
{

public:
	State* Handle() override;
};

