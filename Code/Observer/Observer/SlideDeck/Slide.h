#pragma once
#include <string>

class Slide
{
	std::string m_Title{} ;
	std::string m_Description{} ;

public:
	Slide()=default;
	Slide(std::string mTitle, std::string mDescription);
	void SetTitle(std::string title) ;
	void SetDescription(std::string description) ;
	const std::string & GetTitle()const ;
	const std::string & GetDescription()const ;
};

