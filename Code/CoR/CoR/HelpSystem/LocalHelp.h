#pragma once
#include "HelpHandler.h"
class LocalHelp :
    public HelpHandler
{

public:
	void ShowHelp(const std::string& topic) override;
};

