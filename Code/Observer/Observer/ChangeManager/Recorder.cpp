#include "Recorder.h"

#include <iostream>
#include "Sensor.h"
void Recorder::Notify(Sensor *pSensor) {
	std::cout << "[RECORDER] " << pSensor->GetValue() << '\n' ;
}
