#include "CommandDisplay.h"
#include "Application.h"
void CommandDisplay::Execute(int id) {
	m_pApp->Display() ;
}

void CommandDisplay::Undo() {
}

void CommandDisplay::Redo() {
}
