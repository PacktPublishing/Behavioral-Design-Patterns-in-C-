#include "Billboard.h"

#include <iostream>
#include "Sensor.h"
void Billboard::Notify(Sensor *pSensor) {
	std::cout << "[BILLBOARD] " << pSensor->GetValue() << '\n' ;
}
