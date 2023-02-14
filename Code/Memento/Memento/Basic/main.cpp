#include <iostream>

#include "Caretaker.h"
#include "Originator.h"

void Operate(Caretaker &caretaker, Originator &originator) {
	originator.Input() ;
	auto m = originator.CreateMemento() ;
	caretaker.AddMemento(m) ;
}
int main() {
	Caretaker caretaker ;
	Originator originator ;
	Operate(caretaker, originator) ;
	Operate(caretaker, originator) ;
	Operate(caretaker, originator) ;

	std::cout << "Restoring state\n" ;
	for(int i =2  ; i >= 0 ; --i) {
		originator.SetMemento(caretaker.Restore(i)) ;
		originator.PrintState() ;
	}
	
}
