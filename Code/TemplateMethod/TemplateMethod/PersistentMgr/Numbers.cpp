#include "Numbers.h"

#include <iostream>

void Numbers::Read(std::ifstream& in) {
	if(m_Version == "v1.0"){
		in >> m_Number ;
	}else if(m_Version == "v2.0") {
		in >> m_Number >> m_Num2 ;
	}
}

void Numbers::ReadVersion(std::ifstream& in) {
	in >> m_Version ;
}

void Numbers::Write(std::ofstream& out) {
	out << m_Number << '\n' ;
	out << m_Num2 << '\n' ;
}

void Numbers::WriteVersion(std::ofstream& out) {
	out << "v2.0\n" ;
}

void Numbers::Print() const {
	std::cout << "Number is:" << m_Number << " & " << m_Num2 << '\n';
}

void Numbers::SetNumber(int num) {
	m_Number = num ;
	m_Num2 = num * 100 ;
	SetModified(true) ;
}
