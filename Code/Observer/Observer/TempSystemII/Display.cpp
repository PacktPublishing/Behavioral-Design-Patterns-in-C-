#include "Display.h"

#include <iostream>

void Display::Notify(float value) {
	std::cout << "Display [" << value << "]\n" ;
}
