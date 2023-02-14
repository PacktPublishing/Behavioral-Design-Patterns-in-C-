#pragma once
#include <string>

#include "Command.h"

class MainWindow : public Command
{
	std::string m_Text{} ;
public:
	MainWindow() ;
	void ExecuteFind(const std::string& text) override;
};

