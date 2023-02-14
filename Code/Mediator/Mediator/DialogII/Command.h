#pragma once
#include <string>
class Widget;

class Command
{
public:
	virtual void OnClick(Widget *pWidget, const std::string &message) = 0 ;
	virtual ~Command()=default ;
};

