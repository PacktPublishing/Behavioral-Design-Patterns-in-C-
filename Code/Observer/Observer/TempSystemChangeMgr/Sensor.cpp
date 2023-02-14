#include "Sensor.h"
#include "ChangeManager.h"
Sensor::Sensor(ChangeManager* mPChangeManager): m_pChangeManager{mPChangeManager} {
}

void Sensor::Register(OnValueChanged* p) {
	m_pChangeManager->Register(this, p) ;
}

void Sensor::Deregister(OnValueChanged* p) {
	m_pChangeManager->Deregister(this, p) ;
}

void Sensor::Notify() {
	m_pChangeManager->Notify(this) ;
}
