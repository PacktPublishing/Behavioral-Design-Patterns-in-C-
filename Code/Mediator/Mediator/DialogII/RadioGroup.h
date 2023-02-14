#pragma once
#include "Widget.h"
class RadioGroup :
    public Widget
{
	using Widget::Widget ;
	const char *m_Titles[3]{"Mr. ", "Mrs. ", "Ms. "} ;
	size_t m_Selection{0} ;
public:
	void SetSelection(size_t index) ;
	const char *GetSelection()const ;
};

