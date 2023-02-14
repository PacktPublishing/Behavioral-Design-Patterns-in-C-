#include "DocSaver.h"

#include <iostream>
#include <string>

void DocSaver::New() {
	if(m_Stream.is_open()) {
		m_Stream.close() ;
	}
	std::cout << "File name?" ;
	std::string fileName{} ;
	std::getline(std::cin, fileName) ;
	m_Stream.open(fileName, m_Stream.out) ;
}

void DocSaver::Close() {
	m_Stream.close() ;
}
