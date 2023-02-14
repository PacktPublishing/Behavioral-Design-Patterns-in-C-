#pragma once
#include "DocSaver.h"
class TextDocument :
    public DocSaver
{
	std::string m_Text{} ;
public:
	void Load() override;
	void Save() override;
	void SetText(std::string text) ;
	void Print() ;
};

