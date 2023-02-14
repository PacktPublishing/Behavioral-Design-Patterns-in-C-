#pragma once
#include <string>

#include "Console.h"

class Application
{
	Color       m_Color {Color::WHITE } ;
	bool        m_Bold  { } ;
	std::string m_Text  { } ;
public:
	void AddText(const std::string &text) ;
	void RemoveText(size_t index, size_t count) ;
	void Overwrite(size_t index, const std::string &text) ;
	void SetColor(Color color) ;
	void SetBold(bool bold) ;
	void InsertText(size_t index, const std::string &text) ;
	size_t TextSize()const ;
	bool IsBold()const ;
	Color GetColor()const ;
	void Display() ;
	const std::string & GetText()const ;

};

