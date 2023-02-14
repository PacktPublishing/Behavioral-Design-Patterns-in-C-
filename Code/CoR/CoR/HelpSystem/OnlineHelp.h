#pragma once
#include "HelpHandler.h"
class OnlineHelp :
    public HelpHandler
{

public:
	void ShowHelp(const std::string& topic) override;
};

