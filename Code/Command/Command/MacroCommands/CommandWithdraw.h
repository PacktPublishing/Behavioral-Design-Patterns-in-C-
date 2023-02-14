#pragma once
#include "Command.h"
class Account;

class CommandWithdraw :
    public Command
{
	Account *m_pAccount{} ;
	int m_Amount{} ;

public:
	void Execute() override;
	void Undo() override;

	CommandWithdraw(Account* mPAccount)
		: m_pAccount{mPAccount} {
	}
};

