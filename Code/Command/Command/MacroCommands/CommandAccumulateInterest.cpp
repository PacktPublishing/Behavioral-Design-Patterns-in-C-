#include "CommandAccumulateInterest.h"

#include <iostream>

#include "Account.h"
void CommandAccumulateInterest::Execute() {
	m_Interest = (m_pAccount->GetBalance() * m_InterestRate )/100;
	m_pAccount->Deposit(m_Interest) ;
	std::cout << "[Accumulate Interest]Balance:" << m_pAccount->GetBalance() << '\n' ;
}

void CommandAccumulateInterest::Undo() {
	m_pAccount->Withdraw(m_Interest) ;
}
