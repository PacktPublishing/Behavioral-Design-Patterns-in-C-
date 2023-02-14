#pragma once
#include "Widget.h"
#include "ListBox.h"
#include "RadioGroup.h"
#include "EditBox.h"
#include "Button.h"
class Dialog :
    public Widget, public Command
{
	using Widget::Widget ;
	ListBox m_List{200} ;
	RadioGroup m_RadioGroup{} ;
	EditBox m_EditBox{} ;
	Button m_Button{100} ;
public:
	Dialog() ;
	void SetData(const std::string &text, size_t selection) ;
	void Display()const ;
	void OnClick(Widget* pWidget, const std::string& message) override;
	ListBox * GetListBox() ;
	Button * GetButton() ;
};

