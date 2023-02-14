#pragma once
#include "Handler.h"
class ConcreteHandler1 :
    public Handler
{
	using Handler::Handler ;
	bool m_CanHandle{false} ;
public:
	void Set(bool canHandle) ;
	void HandleRequest() override;
};

