#pragma once
#include "HelpHandler.h"
class QuickHelp :
    public HelpHandler
{

public:
	void ShowHelp(const std::string&topic) override;
};

