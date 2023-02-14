#pragma once
#include <string>
//#include "Organization.h"
using Employee = std::string ;

class EmpIterator {
	const Employee *m_pEmp{} ;
	size_t m_Position{} ;
	size_t m_Size{} ;
public:

	EmpIterator(const Employee* mPEmp, size_t mSize);
	bool IsDone()const;
	void Next();
	const Employee& CurrentItem()const;
};

