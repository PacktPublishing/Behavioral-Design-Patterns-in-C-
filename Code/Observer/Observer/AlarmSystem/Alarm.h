#pragma once
#include <list>

class AlarmObserver;

class Alarm
{
	std::list<AlarmObserver*> m_Observers{} ;
public:
	void Attach(AlarmObserver *pObserver) ;
	void Detach(AlarmObserver *pObserver) ;
	void Notify() ;
	void SetAlarmOn() ;
};

