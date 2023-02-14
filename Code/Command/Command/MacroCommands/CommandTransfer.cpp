#include "CommandTransfer.h"
void CommandTransfer::Execute() {
	m_pFrom->Execute() ;
	m_pTo->Execute() ;
}

void CommandTransfer::Undo() {
	m_pFrom->Undo() ;
	m_pTo->Undo() ;
}
