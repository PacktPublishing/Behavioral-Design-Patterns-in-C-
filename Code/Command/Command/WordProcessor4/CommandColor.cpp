#include "CommandColor.h"

#include <iostream>
#include "Console.h"
#include "Menu.h"
#include "Application.h"
#include "UndoManager.h"

void CommandColor::ReplaceColor() {
	Color color = m_pApp->GetColor() ;
	m_pApp->SetColor(m_Color) ;
	m_Color = color ;
}

void CommandColor::Execute(int id) {
	char chColor{} ;
	
	std::cout << "Choose color (r, g, b, w)?" ;
	std::cin >> chColor ;
	switch(chColor) {
	case 'r':
		m_Color = Color::RED ;
		break ;
	case 'g':
		m_Color = Color::GREEN ;
		break ;
	case 'b' :
		m_Color = Color::BLUE ;
		break ;
	case 'w':
		m_Color = Color::WHITE ;
		break ;
	default:
		Message("Unknown color") ;
		return ; 
	}
	
	ReplaceColor();
	UndoManager::AddCommand(std::make_shared<CommandColor>(*this)) ;
	Message("Color set!") ;
}

void CommandColor::Undo() {
	ReplaceColor();
}

void CommandColor::Redo() {
	ReplaceColor();
}
