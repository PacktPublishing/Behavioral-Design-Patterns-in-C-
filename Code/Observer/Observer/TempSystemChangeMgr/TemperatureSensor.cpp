#include "TemperatureSensor.h"

#include <iostream>
#include "OnValueChanged.h"


void TemperatureSensor::SetTemp(float value) {
	std::cout << "\n\n---------- TEMPERATURE CHANGED ------------\n" ;
	m_Temperature = value ;
	Notify() ;
}

std::any TemperatureSensor::GetValue() {
	return std::make_any<float>(m_Temperature) ;
}

std::string TemperatureSensor::GetType() const {
	return "temperature" ;
}
