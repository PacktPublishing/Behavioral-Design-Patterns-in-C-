#include "Tank.h"

#include <iostream>
#include "Alarm.h"
Tank::Tank(Alarm* mPAlarm): m_pAlarm{mPAlarm} {
	m_pAlarm->Attach(this) ;
}

Tank::~Tank() {
	m_pAlarm->Detach(this) ;
}

void Tank::AlarmOn() {
	std::cout << "Tank alerted! Firing...\n" ;
}
