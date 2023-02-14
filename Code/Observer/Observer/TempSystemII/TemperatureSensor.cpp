#include "TemperatureSensor.h"

#include <iostream>

#include "OnValueChanged.h"

void TemperatureSensor::Notify(std::list<OnValueChanged*> subscribers) {
	for (auto sub : subscribers) {
		sub->Notify(m_Temperature);
	}
}

void TemperatureSensor::Register(Frequency pr, OnValueChanged* p) {
	m_Subscribers[pr].push_back(p);
}

void TemperatureSensor::Deregister(Frequency pr, OnValueChanged* p) {
	m_Subscribers[pr].remove(p);
}

void TemperatureSensor::Notify(float value) {
	if (m_Change > 0.5f) {
		Notify(m_Subscribers[Frequency::LOW]);
	}
	Notify(m_Subscribers[Frequency::HIGH]);
}



void TemperatureSensor::SetTemp(float value) {
	std::cout << "\n\n---------- TEMPERATURE CHANGED ------------\n";
	m_Change = abs(m_Temperature - value);
	m_Temperature = value;
	Notify(m_Temperature);
}

