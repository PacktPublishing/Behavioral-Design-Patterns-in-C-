#pragma once
#include "AlarmObserver.h"
class Alarm;

class Soldier :
    public AlarmObserver
{
	Alarm *m_pAlarm{} ;
public:

	Soldier(Alarm* mPAlarm);
	~Soldier();

	void AlarmOn() override;
};

