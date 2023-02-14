#pragma once
#include "Command.h"
class Receiver;

class ConcreteCommand :
    public Command
{
	Receiver *m_pReceiver ;
	int m_Count{} ;
public:

	ConcreteCommand(Receiver* mPReceiver);
	void Execute() override;
};

