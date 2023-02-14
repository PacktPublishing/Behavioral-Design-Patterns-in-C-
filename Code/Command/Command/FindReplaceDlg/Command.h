#pragma once
#include <string>

class Command
{
public:
	virtual void ExecuteFind(const std::string &text)=0 ;
	virtual ~Command() = default ;
};

