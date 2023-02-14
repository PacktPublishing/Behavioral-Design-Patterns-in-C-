#include "TemperatureSensor.h"

#include <iostream>

#include "OnValueChanged.h"

void TemperatureSensor::Notify(TemperatureChange tc) {
	for(auto sub : m_Subscribers[tc]) {
		sub->Notify(m_Temperature) ;
	}
}

void TemperatureSensor::Register(TemperatureChange tc,OnValueChanged* p) {
	m_Subscribers[tc].push_back(p) ;
}

void TemperatureSensor::Deregister(TemperatureChange tc,OnValueChanged* p) {
	m_Subscribers[tc].remove(p) ;
}

void TemperatureSensor::Notify(float value) {
	if(m_Change > 0.5f) {
		Notify(TemperatureChange::LARGE) ;
	}
	Notify(TemperatureChange::SMALL) ;
}

void TemperatureSensor::SetTemp(float value) {
	std::cout << "\n\n------- TEMPERATURE CHANGED --------\n" ;
	m_Change = abs(m_Temperature-value) ;
	m_Temperature = value ;
	Notify(m_Temperature) ;
}
