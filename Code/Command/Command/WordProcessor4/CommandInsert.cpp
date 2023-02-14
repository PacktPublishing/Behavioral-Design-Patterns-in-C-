

#include <iostream>
#include "Menu.h"
#include "Application.h"
#include "CommandInsert.h"

#include "UndoManager.h"

CommandInsert::CommandInsert(Application* mPApp): m_pApp{mPApp} {
}

void CommandInsert::Execute(int id) {
	std::cout << "Enter text:" ;
	std::cin.ignore() ;
	std::getline(std::cin, m_Text) ;
	std::cout << "Position of insertion:" ;
	size_t index{} ; 
	std::cin >> index ;
	m_Start = index ;
	m_pApp->InsertText(index, m_Text) ;
	UndoManager::AddCommand(std::make_shared<CommandInsert>(*this)) ;
	Message("Text inserted!") ;
}

void CommandInsert::Undo() {
	auto count = m_Text.size() ;
	m_pApp->RemoveText(m_Start, count) ;
}

void CommandInsert::Redo() {
	m_pApp->InsertText(m_Start, m_Text) ;
}
