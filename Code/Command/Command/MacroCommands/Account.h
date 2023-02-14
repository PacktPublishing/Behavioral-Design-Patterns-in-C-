#pragma once
class Account
{
	int m_Balance{} ;
public:

	Account(int mBalance)
		: m_Balance{mBalance} {
	}

	void Deposit(int amount) ;
	void Withdraw(int amount) ;
	int GetBalance()const ;
};

