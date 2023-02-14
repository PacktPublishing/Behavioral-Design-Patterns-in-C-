#include "Dialog.h"

#include <iostream>

Dialog::Dialog() {
	m_Button.SetCommand(this) ;
	m_List.SetCommand(this) ;
}

void Dialog::SetData(const std::string& text, size_t selection) {
	m_EditBox.SetText(text) ;
	m_RadioGroup.SetSelection(selection) ;
}

void Dialog::Display() const {
	std::cout << "[EditBox] -> " << m_EditBox.GetText() << '\n' ;
	std::cout << "[RadioGroup] -> " << m_RadioGroup.GetSelection() << '\n' ;
	std::cout << "[ListBox] -> \n" ;
	m_List.Display() ;
}

void Dialog::OnClick(Widget* pWidget, const std::string& message) {
	switch(pWidget->GetId()) {
	case 100: //Button
	{
		auto text = m_EditBox.GetText() ;
		auto title = m_RadioGroup.GetSelection() ;
		m_List.AddItem(title + text) ;
	}
		break ;
	case 200://ListBox
		if(m_List.GetSelectedItemIndex() != -1) {
			m_EditBox.SetText(m_List.GetSelectedItem()) ;
		}
		break ;
	}
}

ListBox* Dialog::GetListBox() {
	return &m_List ;
}

Button* Dialog::GetButton() {
	return &m_Button ;
}
