#include "SimpleChangeManager.h"
#include "OnValueChanged.h"
void SimpleChangeManager::Deregister(Sensor* pSubject, OnValueChanged* pChanged) {
	m_Mapping[pSubject].remove(pChanged) ;
}

void SimpleChangeManager::Notify(Sensor* pSubject) {
	for(auto observer : m_Mapping[pSubject]) {
		observer->Notify(pSubject) ;
	}
	
}

void SimpleChangeManager::Register(Sensor* pSubject, OnValueChanged* pChanged) {
	m_Mapping[pSubject].push_back(pChanged) ;
}
