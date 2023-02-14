#pragma once
#include "Widget.h"


class EditBox :
    public Widget
{
	using Widget::Widget ;
	std::string m_Text{} ;
public:
	void SetText(std::string text) ;
	const std::string & GetText()const ;
};

