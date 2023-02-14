#pragma once
#include "Command.h"
class Account;

class CommandDeposit :
    public Command
{
	Account *m_pAccount{} ;
	int m_Amount{} ;
public:
	CommandDeposit(Account* mPAccount)
		: m_pAccount{mPAccount} {
	}

	void Execute() override;
	void Undo() override;
};

