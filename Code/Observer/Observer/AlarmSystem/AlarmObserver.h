#pragma once
class AlarmObserver
{
public:
	virtual void AlarmOn() = 0 ;
	virtual ~AlarmObserver()=default ;
};

