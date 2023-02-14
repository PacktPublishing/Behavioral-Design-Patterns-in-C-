#include "TemperatureSensor.h"
#include "OnValueChanged.h"
void TemperatureSensor::Register(OnValueChanged* p) {
	m_Subscribers.push_back(p) ;
}

void TemperatureSensor::Deregister(OnValueChanged* p) {
	m_Subscribers.remove(p) ;
}

void TemperatureSensor::Notify(float value) {
	for(auto subs : m_Subscribers) {
		subs->Notify(value) ;
	}
}

void TemperatureSensor::SetTemp(float value) {
	m_Temperature = value ;
	Notify(m_Temperature) ;
}
