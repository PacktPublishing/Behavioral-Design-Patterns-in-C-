#pragma once
class Colleague ;
class Mediator
{
public:
	virtual void OnInvoke(Colleague *pColleague) = 0;
	virtual ~Mediator()=default ;
};

