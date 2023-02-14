#pragma once
#include <iostream>
class Lamp;

class State
{
public:
	virtual void SwitchOn(Lamp* pLamp) = 0;
	virtual void SwitchOff(Lamp* pLamp) = 0;
	virtual ~State() {
		std::cout << __FUNCSIG__ << '\n';
	}
};

