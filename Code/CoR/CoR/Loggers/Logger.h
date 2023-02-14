#pragma once
#include <string_view>

class Logger
{
protected:
	Logger *m_pNext{} ;
public:
	Logger(Logger* mPNext)
		: m_pNext{mPNext} {
	}

	virtual void Log(std::string_view message, std::string_view type) = 0 ;
	virtual ~Logger() = default ;
};

