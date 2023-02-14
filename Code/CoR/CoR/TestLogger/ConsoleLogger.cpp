#include "ConsoleLogger.h"

#include <iostream>

void ConsoleLogger::Log(std::string_view message, std::string_view type) {
	if(type == "CONSOLE") {
		std::cerr << "[ConsoleLogger]" << message << '\n' ;
	}else if(m_pNext) {
		std::cout << "[CL] Forwarding\n" ;
		m_pNext->Log(message, type) ;
	}else {
		std::cout << "Unable to log\n" ;
	}
}
