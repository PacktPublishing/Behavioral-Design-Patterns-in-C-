#pragma once
#include <string>
#include <string_view>
#include <fstream>

#include "Logger.h"

class FileLogger: public Logger
{
	std::ofstream m_Stream{} ;
public:
	FileLogger(std::string_view fileName):m_Stream{fileName.data()},Logger{nullptr} {
		
	}
	FileLogger(Logger* mPNext, const std::string& fileName)
		: Logger{mPNext},
		  m_Stream{fileName} {
	}

	void Log(std::string_view message, std::string_view type)override ;
	void Log(std::string_view message) ;
};

