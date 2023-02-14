#include "FindDialog.h"
#include "Command.h"
void FindDialog::SetSearchText(const std::string& text) {
	m_SearchText = text ;
}

void FindDialog::Find() {
	m_pCmd->ExecuteFind(m_SearchText) ;
}
