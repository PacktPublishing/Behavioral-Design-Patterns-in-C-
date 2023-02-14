#pragma once
#include <string>

#include "BalanceMemento.h"

class Account
{
	int m_Balance{} ;
public:

	Account(int mBalance);
	bool Withdraw(int amount) ;
	void Deposit(int amount) ;
	int GetBalance()const ;
	void AccumulateInterest(int interestRate) ;
	BalanceMemento CreateMemento() ;
	void ShowBalance(const std::string &transactionType)const ;
	void Restore(BalanceMemento memento) ;
};

