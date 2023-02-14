#pragma once
#include <string>
class HelpHandler ;

class Button{
	HelpHandler *m_pHelp{} ;
public:
	void SetHelpHandler(HelpHandler *p) ;
	void RequestHelp(const std::string &topic) ;
};

