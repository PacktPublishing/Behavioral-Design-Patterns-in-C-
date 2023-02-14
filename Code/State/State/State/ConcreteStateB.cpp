#include "ConcreteStateB.h"

#include <iostream>

#include "ConcreteStateA.h"

State* ConcreteStateB::Handle() {
	std::cout << "[ConcreteStateB] State B behavior\n" ;
	return new ConcreteStateA{} ;
}
