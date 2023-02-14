#include "Recorder.h"

#include <iostream>

void Recorder::Notify(float value) {
	std::cout << "Recording [" << value << "]\n" ;
}
