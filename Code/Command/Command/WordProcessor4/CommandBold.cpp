#include "CommandBold.h"

#include <iostream>

#include "Application.h"
#include "Menu.h"
#include "UndoManager.h"

void CommandBold::Execute(int id) {
	bool bold{} ;
	std::cout <<"Press (b) for bold or any other key for normal text:" ;
	char ch ;
	std::cin >> ch ;
	m_Bold = m_pApp->IsBold() ;
	m_pApp->SetBold(ch == 'b'? true :false);
	
	UndoManager::AddCommand(std::make_shared<CommandBold>(*this)) ;
	Message("Text property changed!") ;
}

void CommandBold::Undo() {
	auto bold = m_pApp->IsBold() ;
	m_pApp->SetBold(m_Bold) ;
	m_Bold = bold; 
}

void CommandBold::Redo() {
	Undo() ;
}
