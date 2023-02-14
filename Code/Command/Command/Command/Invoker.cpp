#include "Invoker.h"
#include "Command.h"
void Invoker::SetCommand(Command* pCmd) {
	m_pCommand = pCmd ;
}

void Invoker::Invoke() {
	m_pCommand->Execute() ;
}
