#pragma once
#include "Participant.h"
class Person :
    public Participant
{

public:
	void Send(const std::string& to, const std::string& message) override;
	void Receive(const std::string& from, const std::string& message) override;
};

