#include "TemperatureSensor.h"
#include "OnValueChanged.h"
#include "ChangeManager.h"
TemperatureSensor::TemperatureSensor(ChangeManager* pMgr): m_pMgr(pMgr) {
}

void TemperatureSensor::Notify() {
	m_pMgr->Notify(this) ;
}

float TemperatureSensor::GetValue() const {
	return m_Temperature ;
}

void TemperatureSensor::SetTemp(float value) {
	m_Temperature = value ;
	Notify() ;
}
