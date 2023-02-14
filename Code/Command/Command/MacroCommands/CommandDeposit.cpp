#include "CommandDeposit.h"

#include <iostream>

#include "Account.h"
void CommandDeposit::Execute() {
	std::cout << "Amount to deposit?" ;
	std::cin >> m_Amount ;
	m_pAccount->Deposit(m_Amount) ;
	std::cout << "[Deposit]Balance:" << m_pAccount->GetBalance() << '\n' ;
}

void CommandDeposit::Undo() {
	m_pAccount->Withdraw(m_Amount) ;
	std::cout << "[Undo Deposit]Balance:" << m_pAccount->GetBalance() << '\n' ;
}
