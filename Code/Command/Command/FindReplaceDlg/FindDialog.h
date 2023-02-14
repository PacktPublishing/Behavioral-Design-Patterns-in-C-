#pragma once
#include <string>

class Command;

class FindDialog
{
	std::string m_SearchText{} ;
	Command *m_pCmd{} ;
public:
	FindDialog(Command* mPCmd)
		: m_pCmd{mPCmd} {
	}

	void SetSearchText(const std::string &text) ;
	void Find() ;
};

