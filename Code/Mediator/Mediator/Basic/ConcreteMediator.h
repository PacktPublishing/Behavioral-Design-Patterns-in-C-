#pragma once
#include "Mediator.h"
class Colleague;

class ConcreteMediator :
    public Mediator
{
	Colleague *m_pColleague1{} ;
	Colleague *m_pColleague2{} ;
public:
	void SetColleagues(Colleague *pC1, Colleague *pC2) ;

	void OnInvoke(Colleague* pColleague) override;
};

