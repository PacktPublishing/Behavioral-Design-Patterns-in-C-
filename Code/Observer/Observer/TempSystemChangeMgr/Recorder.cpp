#include "Recorder.h"
#include "Sensor.h"
#include <iostream>

void Recorder::Notify(Sensor* pSubject) {
	std::cout << "Recording...";
	auto value = pSubject->GetValue();
	if (pSubject->GetType() == "temperature") {
		std::cout << std::any_cast<float>(value);
	}
	else if (pSubject->GetType() == "windspeed") {
		std::cout << std::any_cast<float>(value) << " km/h" ;

	}
	std::cout << "]\n";
}
