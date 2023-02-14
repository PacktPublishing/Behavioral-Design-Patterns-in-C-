#include "Receiver.h"

#include <iostream>

void Receiver::Action() {
	std::cout << "[Receiver] Action performed\n" ;
}

void Receiver::Execute() {
	Action() ;
}
