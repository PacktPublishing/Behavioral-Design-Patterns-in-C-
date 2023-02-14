#include "Account.h"

#include <stdexcept>

void Account::Deposit(int amount) {
	m_Balance += amount ;
}

void Account::Withdraw(int amount) {
	if(amount > m_Balance) {
		throw std::runtime_error{"Insufficient balance"} ;
	}
	m_Balance -= amount ;
}

int Account::GetBalance() const {
	return m_Balance ;
}
