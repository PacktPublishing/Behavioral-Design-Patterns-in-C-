#include "Organization.h"
void Organization::AddEmployee(const Employee& emp) {
	m_Employees[m_Count++] = emp ;
}

size_t Organization::Size() const {
	return m_Count ;
}

EmpIterator Organization::CreateIterator() {
	return EmpIterator{m_Employees, m_Count} ;
}
