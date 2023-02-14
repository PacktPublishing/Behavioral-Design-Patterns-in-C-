#include "Button.h"
#include "HelpHandler.h"
void Button::SetHelpHandler(HelpHandler* p) {
	m_pHelp = p ;
}

void Button::RequestHelp(const std::string &topic) {
	m_pHelp->ShowHelp(topic) ;
}
