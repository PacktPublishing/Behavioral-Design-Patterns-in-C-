#include "ComplexChangeManager.h"

void ComplexChangeManager::Deregister(Sensor* pSubject, OnValueChanged* pChanged) {
	m_Mapping[pSubject].remove(pChanged) ;
}

void ComplexChangeManager::Notify(Sensor* pSubject) {
}

void ComplexChangeManager::Register(Sensor* pSubject, OnValueChanged* pChanged) {
	m_Mapping[pSubject].push_back(pChanged) ;
}
