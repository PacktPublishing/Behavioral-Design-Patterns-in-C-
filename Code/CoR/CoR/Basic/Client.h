#pragma once
class Handler;

class Client
{
	Handler *m_pHandler{} ;
public:
	void SetHandler(Handler *pHandler) ;
	void Request() ;
};

