#pragma once
#include <string>

#include "Console.h"
#include "Command.h"

class Application: public Command
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
	void Display() ;

	void Execute(int id) override;

	void InputAdd() ;
	void InputRemove() ;
	void InputOverwrite() ;
	void InputSetColor() ;
	void InputSetBold() ;
	void InputInsert() ;
};

