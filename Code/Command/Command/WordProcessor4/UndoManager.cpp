#include "UndoManager.h"

#include "Menu.h"
#include "Command.h"

void UndoManager::AddCommand(std::shared_ptr<Command> pCommand) {
	m_Undo.push(pCommand);
	while (!m_Redo.empty()) {
		m_Redo.pop();
	}
	m_IsUndo = false;
	return;
}

void UndoManager::RemoveCommand(std::shared_ptr<Command>) {

}

bool UndoManager::Undo() {
	if (m_Undo.empty()) {
		return false;
	}
	auto pCmd = m_Undo.top();
	m_Undo.pop();
	m_Redo.push(pCmd);
	pCmd->Undo();
	m_IsUndo = true;
	return true;
}

bool UndoManager::Redo() {
	if (m_Redo.empty()) {
		return false;
	}
	auto pCmd = m_Redo.top();
	m_Redo.pop();
	m_Undo.push(pCmd);
	pCmd->Redo();
	return true;
}
/*
 * C++
 * Python
 */