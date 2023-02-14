#pragma once
#include <string_view>

#include "Logger.h"

class DbLogger: public Logger
{
	using Logger::Logger ;
public:
	void Log(std::string_view message, std::string_view type)override ;
};

