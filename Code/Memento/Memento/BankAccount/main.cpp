#include <iostream>
#include <stack>
#include <vector>

#include "Account.h"

int main() {
	std::stack<BalanceMemento> transactions{} ;
	Account account{1000} ;
	transactions.push(account.CreateMemento()) ;
	account.Deposit(500) ;
	transactions.push(account.CreateMemento()) ;
	account.Withdraw(200) ;
	transactions.push(account.CreateMemento()) ;
	account.Withdraw(800) ;

	std::cout << "Rollback\n" ;
	while(!transactions.empty()){
		auto m = transactions.top() ;
		account.Restore(m) ;
		transactions.pop() ;
	}
}
