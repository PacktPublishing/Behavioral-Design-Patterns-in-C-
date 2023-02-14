#include "Soldier.h"

#include <iostream>
#include "Alarm.h"
Soldier::Soldier(Alarm* mPAlarm): m_pAlarm{mPAlarm} {
	m_pAlarm->Attach(this) ;
}

Soldier::~Soldier() {
	m_pAlarm->Detach(this) ;
}

void Soldier::AlarmOn() {
	std::cout << "Soldier alerted! Firing...\n" ;
}
