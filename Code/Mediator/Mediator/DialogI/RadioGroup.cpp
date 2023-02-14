#include "RadioGroup.h"

void RadioGroup::SetSelection(size_t index) {
	m_Selection = index ;
	SendMessage("RadioGroup::SetSelection") ;
}

const char* RadioGroup::GetSelection() const {
	return m_Titles[m_Selection] ;
}
