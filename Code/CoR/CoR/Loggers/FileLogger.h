#pragma once
#include <string>
#include <string_view>
#include <fstream>

#include "Logger.h"

class FileLogger: public Logger
{
	std::ofstream m_Stream{} ;
public:
	FileLogger(Logger* mPNext, const std::string& fileName)
		: Logger{mPNext},
		  m_Stream{fileName} {
	}

	void Log(std::string_view message, std::string_view type)override ;
};

