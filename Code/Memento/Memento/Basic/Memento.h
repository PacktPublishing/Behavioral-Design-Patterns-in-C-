#pragma once
#include <string>

class Memento
{
	std::string m_State{} ;
public:

	Memento(const std::string& mState)
		: m_State{mState} {
	}

	void SetState(const std::string &state) ;
	const std::string & GetState()const ;
};

