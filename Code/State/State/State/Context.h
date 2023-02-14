#pragma once
class State;

class Context
{
	State *m_pState{} ;
public:
	Context(State* pState);

	void Request() ;
};

