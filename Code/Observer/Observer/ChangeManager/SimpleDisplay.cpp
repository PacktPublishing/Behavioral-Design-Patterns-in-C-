#include "SimpleDisplay.h"

#include <iostream>
#include "Sensor.h"
void SimpleDisplay::Notify(Sensor *pSensor) {
	std::cout << "[SIMPLEDISPLAY] " << pSensor->GetValue() << '\n' ;
}
