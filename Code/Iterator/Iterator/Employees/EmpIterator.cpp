#include "EmpIterator.h"

EmpIterator::EmpIterator(const Employee* mPEmp,  size_t mSize): m_pEmp{mPEmp},
	m_Size{mSize} {
}

bool EmpIterator::IsDone() const {
	return m_Position == m_Size ;
}

void EmpIterator::Next() {
	++m_Position ;
}

const Employee& EmpIterator::CurrentItem() const {
	return m_pEmp[m_Position] ;
}
