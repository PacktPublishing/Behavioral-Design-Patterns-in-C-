#include <iostream>

#include "Organization.h"

int main() {
	Organization organization ;
	organization.AddEmployee("Umar") ;
	organization.AddEmployee("Ayaan") ;
	organization.AddEmployee("Raihaan") ;

	auto cursor = organization.Create() ;
	while(organization.HasNext(cursor)) {
		std::cout << organization.GetAt(cursor) << ' ' ;
		organization.Next(cursor) ;
	}
	
	/*auto itr = organization.CreateIterator() ;
	while(!itr.IsDone()) {
		std::cout << itr.CurrentItem() << ' ' ;
		itr.Next() ;
	}*/
	
}
