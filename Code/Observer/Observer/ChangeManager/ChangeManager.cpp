#include "ChangeManager.h"
#include "OnValueChanged.h"
void ChangeManager::Register(Sensor* pSensor, OnValueChanged* pValueChanged) {
	m_Mapping[pSensor].push_back(pValueChanged) ;
}

void ChangeManager::DeRegister(Sensor* pSensor, OnValueChanged* pValueChanged) {
	m_Mapping[pSensor].remove(pValueChanged) ;
}

void ChangeManager::Notify(Sensor* pSensor) {
	for(auto observer : m_Mapping[pSensor]) {
		observer->Notify(pSensor) ;
	}
}
