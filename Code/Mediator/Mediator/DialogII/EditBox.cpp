#include "EditBox.h"
#include "ListBox.h"


void EditBox::SetText(std::string text) {
	m_Text = std::move(text) ;
}

const std::string& EditBox::GetText() const {
	return m_Text ;
}
