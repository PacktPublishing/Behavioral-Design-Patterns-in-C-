#include "CommandWithdraw.h"

#include <iostream>
#include "Account.h"
void CommandWithdraw::Execute() {
	std::cout << "Amount to withdraw?" ;
	std::cin >> m_Amount ;
	m_pAccount->Withdraw(m_Amount) ;
	std::cout << "[Withdraw] Balance:" << m_pAccount->GetBalance() << '\n' ;
}

void CommandWithdraw::Undo() {
	m_pAccount->Deposit(m_Amount) ;
	std::cout << "[Undo Withdraw] Balance:" << m_pAccount->GetBalance() << '\n' ;
}
