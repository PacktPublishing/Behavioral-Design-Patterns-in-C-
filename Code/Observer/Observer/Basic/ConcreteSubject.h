#pragma once
#include <string>

#include "Subject.h"
class ConcreteSubject :
    public Subject
{
	std::string m_SubjectState{} ;
public:
	const std::string & GetState()const ;
	void SetState(std::string state) ;
};

