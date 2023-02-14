#pragma once
#include "AlarmObserver.h"
class Alarm;

class HeavyGunner :
    public AlarmObserver
{
	Alarm *m_pAlarm{} ;
public:

	HeavyGunner(Alarm* mPAlarm);
	~HeavyGunner(); 
	void AlarmOn() override;
};

