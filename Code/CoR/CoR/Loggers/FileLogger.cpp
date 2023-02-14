#include "FileLogger.h"

#include <iostream>

void FileLogger::Log(std::string_view message, std::string_view type) {
	if(type == "FILE") {
		m_Stream << message << '\n' ;
		m_Stream.flush() ;
	}else if(m_pNext) {
		std::cout << "[FL] Forwarding\n" ;
		m_pNext->Log(message, type) ;
	}else {
		std::cout << "Unable to log\n" ;
	}
}
