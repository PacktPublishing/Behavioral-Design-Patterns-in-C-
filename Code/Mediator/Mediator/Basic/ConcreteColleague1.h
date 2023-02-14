#pragma once
#include "Colleague.h"
class ConcreteColleague1 :
    public Colleague
{
	using Colleague::Colleague;
public:

	void SendMessageA() override;
	void SendMessageB() override;
	std::string GetType() const override;
};

