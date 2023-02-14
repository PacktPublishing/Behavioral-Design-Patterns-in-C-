#include "EditBox.h"
#include "ListBox.h"

void EditBox::SetListBox(ListBox* pListBox) {
	m_pListBox = pListBox ;
}

void EditBox::OnClick(Widget* pWidget, const std::string& message) {
	m_Text = m_pListBox->GetSelectedItem() ;
}

void EditBox::SetText(std::string text) {
	m_Text = std::move(text) ;
}

const std::string& EditBox::GetText() const {
	return m_Text ;
}
