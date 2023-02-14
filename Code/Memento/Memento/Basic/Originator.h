#pragma once
#include <string>

#include "Memento.h"

class Originator
{
	std::string m_State{} ;
public:
	Memento CreateMemento()const ;
	void SetMemento(Memento memento) ;
	void Input() ;
	void PrintState() ;
};

