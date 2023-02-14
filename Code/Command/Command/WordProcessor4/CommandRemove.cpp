#include "CommandRemove.h"

#include <iostream>


#include "Menu.h"
#include "Application.h"
#include "UndoManager.h"

void CommandRemove::Execute(int id) {
	size_t count{} ;
	std::cout << "Starting index?" ;
	std::cin >> m_Start ;
	std::cout << "How many characters to remove?" ;
	std::cin >> count;
	
	m_Text = m_pApp->GetText().substr(m_Start, count) ;
	m_pApp->RemoveText(m_Start, count ) ;
	
	UndoManager::AddCommand(std::make_shared<CommandRemove>(*this)) ;
	Message("Text removed!") ;
}

void CommandRemove::Undo() {
	m_pApp->InsertText(m_Start, m_Text) ;
}

void CommandRemove::Redo() {
	auto count = m_Text.size() ;
	m_Text = m_pApp->GetText().substr(m_Start, count) ;
	m_pApp->RemoveText(m_Start, count ) ;
}
