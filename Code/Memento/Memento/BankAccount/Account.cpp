#include "Account.h"

#include <iostream>

Account::Account(int mBalance): m_Balance{mBalance} {
	ShowBalance("New Account") ;
}

bool Account::Withdraw(int amount) {
	if(amount > m_Balance) {
		return false ;
	}
	m_Balance -= amount ;
	ShowBalance("Withdraw") ;
	return true ;
}

void Account::Deposit(int amount) {
	m_Balance += amount ;
	ShowBalance("Deposit") ;
}

int Account::GetBalance() const {
	return m_Balance ;
}

void Account::AccumulateInterest(int interestRate) {
	m_Balance += (m_Balance * interestRate)/100 ;
}

BalanceMemento Account::CreateMemento() {
	return {m_Balance} ;
}

void Account::ShowBalance(const std::string &transactionType) const {
	std::cout << "\n==== " << transactionType << " ====\n" ;
	std::cout << "Balance => " << m_Balance << "\n\n" ;
}

void Account::Restore(BalanceMemento memento) {
	m_Balance = memento.GetBalance() ;
	ShowBalance("Restore") ;
}
