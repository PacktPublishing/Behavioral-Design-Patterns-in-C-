#pragma once
#include <list>
class View;

class Publisher
{
	std::list<View*> m_Views{} ;
public:
	void RegisterView(View *pView) ;
	void DeregisterView(View *pView) ;
	void Notify(int index) ;
};

