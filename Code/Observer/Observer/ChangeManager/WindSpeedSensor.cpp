#include "WindSpeedSensor.h"
#include "ChangeManager.h"
WindSpeedSensor::WindSpeedSensor(ChangeManager* pMgr): m_pMgr(pMgr) {
}

float WindSpeedSensor::GetValue() const {
	return m_Speed ;
}

void WindSpeedSensor::Notify() {
	m_pMgr->Notify(this) ;
}
void WindSpeedSensor::SetSpeed(float speed) {
	m_Speed = speed ;
	Notify() ;
}
