#include "SimpleDisplay.h"

#include <iostream>

void SimpleDisplay::Notify(float value) {
	std::cout << "[SIMPLEDISPLAY] " << value << '\n' ;
}
