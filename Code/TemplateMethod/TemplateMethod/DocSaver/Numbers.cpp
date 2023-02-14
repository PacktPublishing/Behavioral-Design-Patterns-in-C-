#include "Numbers.h"


#include <iostream>
#include <string>

void Numbers::SetNumber(int num) {
	m_IsModified = true;
	m_Number = num;
}

void Numbers::Print() {
	std::cout << "Number is:" << m_Number << '\n';
}

void Numbers::Load() {
	if (m_IsModified) {
		std::cout << "Save current changes first\n";
		return;
	}
	std::cout << "File name?";
	std::string fileName{};
	std::getline(std::cin, fileName);
	m_Stream.open(fileName, m_Stream.in);
	std::string version{};
	m_Stream >> version;
	if (version == "v1.0") {
		m_Stream >> m_Number;
	}
	m_Stream.close();
}

void Numbers::Save() {
	if (m_Number == 0)
		return;
	if (!m_Stream.is_open()) {
		std::cout << "File name?";
		std::string fileName{};
		std::getline(std::cin, fileName);
		m_Stream.open(fileName, m_Stream.out);
	}
	m_Stream.seekp(0);
	m_Stream << "v1.0\n";
	m_Stream << m_Number ;
}
