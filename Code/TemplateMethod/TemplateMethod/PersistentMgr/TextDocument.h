#pragma once
#include "DocSaver.h"

class TextDocument : public DocSaver
{
	std::string m_Text{} ;
protected:
	void Read(std::ifstream &in) override;
	void Write(std::ofstream & out) override;
public:
	void SetText(std::string text) ;
	void Print() ;
};

