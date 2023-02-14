#pragma once
#include "Observer.h"
class ConcreteSubject;

class ConcreteObserver :
    public Observer
{
	ConcreteSubject *m_pSubject{} ;
public:

	ConcreteObserver(ConcreteSubject* mPSubject);

	void Update() override;
};

