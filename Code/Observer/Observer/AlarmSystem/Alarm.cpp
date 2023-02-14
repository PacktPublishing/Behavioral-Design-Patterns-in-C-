#include "Alarm.h"
#include "AlarmObserver.h"
void Alarm::Attach(AlarmObserver* pObserver) {
	m_Observers.push_back(pObserver) ;
}

void Alarm::Detach(AlarmObserver* pObserver) {
	m_Observers.remove(pObserver) ;
}

void Alarm::Notify() {
	for(auto observer : m_Observers) {
		observer->AlarmOn() ;
	}
}

void Alarm::SetAlarmOn() {
	Notify() ;
}
