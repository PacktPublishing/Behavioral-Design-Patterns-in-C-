#include "HeavyGunner.h"

#include <iostream>
#include "Alarm.h"
HeavyGunner::HeavyGunner(Alarm* mPAlarm): m_pAlarm{mPAlarm} {
	m_pAlarm->Attach(this) ;
}

HeavyGunner::~HeavyGunner() {
	m_pAlarm->Detach(this) ;
}

void HeavyGunner::AlarmOn() {
	std::cout << "HeavyGunner alerted! Launching rocket...\n" ;
}
