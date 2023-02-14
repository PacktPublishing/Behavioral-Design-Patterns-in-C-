#include "ConcreteStateA.h"

#include <iostream>

#include "ConcreteStateB.h"

State* ConcreteStateA::Handle() {
	std::cout << "[ConcreteStateA] State A behavior\n" ;
	return new ConcreteStateB{} ;
}
