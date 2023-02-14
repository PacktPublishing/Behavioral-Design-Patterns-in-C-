#pragma once
#include "Widget.h"

class ListBox;

class EditBox :
    public Widget, public Command
{
	std::string m_Text{} ;
	ListBox *m_pListBox{} ;
public:
	void SetListBox(ListBox *pListBox) ;
	void OnClick(Widget* pWidget, const std::string& message) override;
	void SetText(std::string text) ;
	const std::string & GetText()const ;
};

