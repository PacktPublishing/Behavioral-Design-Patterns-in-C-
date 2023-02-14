#pragma once
class Handler
{
protected:
	Handler *m_pNext{} ;

public:
	Handler(Handler* mPNext)
		: m_pNext{mPNext} {
	}
	virtual void HandleRequest() = 0 ;
	virtual ~Handler()=default ;
};

