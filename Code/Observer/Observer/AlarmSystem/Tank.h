#pragma once
#include "AlarmObserver.h"
class Alarm;

class Tank :
    public AlarmObserver
{
	Alarm *m_pAlarm{} ;
public:
	Tank(Alarm* mPAlarm);
	~Tank();
	void AlarmOn() override;
};

