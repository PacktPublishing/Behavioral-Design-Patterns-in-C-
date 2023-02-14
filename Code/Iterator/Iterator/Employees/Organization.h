#pragma once
#include <string>
#include "EmpIterator.h"
using Employee = std::string ;
//Memento
class Cursor {
		Employee *m_ptr{} ;

		Cursor(Employee* mPtr)
			: m_ptr{mPtr} {
		}
		friend class Organization ;
	};
class Organization
{
	static constexpr size_t MAX{10} ;
	Employee m_Employees[MAX] ;
	size_t m_Count{} ;
public:
	
	Cursor * Create() {
		return new Cursor{m_Employees} ;
	}
	void Next(Cursor *&cursor) {
		cursor->m_ptr++ ;
	}
	const Employee & GetAt(Cursor *cursor) {
		return *cursor->m_ptr ;
	}
	bool HasNext(Cursor *cursor) {
		return cursor->m_ptr != (m_Employees + m_Count) ;
	}
	void AddEmployee(const Employee &emp) ;
	size_t Size()const ;
	EmpIterator CreateIterator() ;
};
