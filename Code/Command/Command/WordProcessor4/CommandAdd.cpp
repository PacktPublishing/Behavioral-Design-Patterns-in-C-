#include "CommandAdd.h"

#include <iostream>
#include "Menu.h"
#include "Application.h"
#include "UndoManager.h"

CommandAdd::CommandAdd(Application* mPApp): m_pApp{mPApp} {
}

void CommandAdd::Execute(int id) {
	std::cout << "Enter text to add:" ;
	std::cin.ignore() ;
	std::getline(std::cin, m_Text) ;
	m_pApp->AddText(m_Text) ;
	
	UndoManager::AddCommand(std::make_shared<CommandAdd>(*this)) ;
	Message("Text added successfully!") ;
}

void CommandAdd::Undo() {
	auto count = m_Text.size() + 1 ; //To account for extra space at the end
	auto index = m_pApp->TextSize() - count;
	m_pApp->RemoveText(index, count) ;
}

void CommandAdd::Redo() {
	m_pApp->AddText(m_Text) ;
}
