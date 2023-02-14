#pragma once
#include "Command.h"
class Account;

class CommandAccumulateInterest :
    public Command
{
	const int m_InterestRate;
	Account *m_pAccount{} ;
	int m_Interest{} ;

public:
	CommandAccumulateInterest(int mInterest, Account* mPAccount)
		: m_InterestRate{mInterest},
		  m_pAccount{mPAccount} {
	}

	void Execute() override;
	void Undo() override;
};

