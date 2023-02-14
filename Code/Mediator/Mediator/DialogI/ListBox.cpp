#include "ListBox.h"

#include <iostream>
#include "EditBox.h"
#include "RadioGroup.h"
void ListBox::SetEditBox(EditBox* pEditBox) {
	m_pEditBox = pEditBox ;
}

void ListBox::SetRadioGroup(RadioGroup* pRadioGroup) {
	m_pRadioGroup = pRadioGroup ;
}

void ListBox::OnClick(Widget* pWidget, const std::string& message) {
	auto name = m_pEditBox->GetText() ;
	auto title = m_pRadioGroup->GetSelection() ;
	m_Items.push_back(title + name) ;
}

void ListBox::AddItem(std::string item) {
	m_Items.push_back(std::move(item)) ;
	SendMessage("ListBox::SelectItem") ;
}

void ListBox::SelectItem(int index) {
	m_SelectedItem = index ;
	SendMessage("ListBox::SelectItem") ;
}

const std::string& ListBox::GetSelectedItem() const {
	return m_Items[m_SelectedItem] ;
}

void ListBox::Display() const {
	for(size_t i = 0 ; i < m_Items.size() ; ++i) {
		std::cout << '\t' << m_Items[i] ;
		if(i == m_SelectedItem) {
			std::cout << '*' ;
		}
		std::cout << '\n' ;
	}
	std::cout << '\n' ;
}
