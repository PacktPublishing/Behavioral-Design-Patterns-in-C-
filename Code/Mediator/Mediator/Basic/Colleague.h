#pragma once
#include <string>
class Mediator;

class Colleague
{
protected:
	Mediator *m_pMediator{} ;
public:
	Colleague(Mediator* pMediator)
		: m_pMediator(pMediator) {
	}
	virtual void SendMessageA() = 0 ;
	virtual void SendMessageB() = 0 ;
	virtual std::string GetType() const = 0 ;
	virtual ~Colleague()=default ;
};

