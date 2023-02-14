#include "CommandOverwrite.h"

#include <iostream>


#include "Menu.h"
#include "Application.h"
#include "UndoManager.h"

void CommandOverwrite::Execute(int id) {
	std::string text ;
	std::cout << "Enter text:" ;
	std::cin.ignore() ;
	std::getline(std::cin, text) ;
	std::cout << "Position of overwrite:" ;
	std::cin >> m_Start ;
	
	m_Text = m_pApp->GetText().substr(m_Start, text.size()) ;
	
	m_pApp->Overwrite(m_Start, text) ;
	UndoManager::AddCommand(std::make_shared<CommandOverwrite>(*this)) ;
	Message("Text overwritten!") ;
}

void CommandOverwrite::Undo() {
	auto text = m_pApp->GetText().substr(m_Start, m_Text.size()) ;
	m_pApp->Overwrite(m_Start, m_Text) ;
	m_Text = text ;
}

void CommandOverwrite::Redo() {
	Undo() ;
	
}
