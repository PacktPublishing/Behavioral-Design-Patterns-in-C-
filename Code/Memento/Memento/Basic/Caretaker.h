#pragma once
#include <vector>

#include "Memento.h"

class Caretaker
{
	std::vector<Memento> m_States{} ;
public:
	void AddMemento(Memento m) ;
	Memento Restore(size_t index) ;
	
};

