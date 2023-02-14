#include <iostream>

#include "Account.h"
#include "CommandDeposit.h"
#include "CommandTransfer.h"
#include "CommandWithdraw.h"

int main() {
	Account accA{1000} ;
	Account accB{5000} ;
	CommandWithdraw cmdWithdraw{&accA} ;
	CommandDeposit cmdDeposit{&accA} ;

	std::cout << "Initial balance:" << accA.GetBalance() << std::endl; 
	cmdWithdraw.Execute() ;
	cmdDeposit.Execute() ;

	CommandTransfer cmdTransfer{&cmdDeposit, &cmdWithdraw} ;
	cmdTransfer.Execute() ;
	
	std::cout << "Undo\n" ;
	cmdTransfer.Undo() ;
	cmdDeposit.Undo() ;
	cmdWithdraw.Undo() ;
}
