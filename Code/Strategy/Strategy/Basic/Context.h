#pragma once
class Strategy ;
class Context
{
	Strategy *m_pStrategy{} ;
public:
	void ContextInterface() ;
	void SetStrategy(Strategy *p) ;
};

