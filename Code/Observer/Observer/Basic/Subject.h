#pragma once
#include <list>
class Observer;

class Subject
{
	std::list<Observer*> m_Observers{} ;
public:
	void Attach(Observer *pObserver) ;
	void Detach(Observer *pObserver) ;
	void Notify() ;
	virtual ~Subject() =0 {
		
	}
};

