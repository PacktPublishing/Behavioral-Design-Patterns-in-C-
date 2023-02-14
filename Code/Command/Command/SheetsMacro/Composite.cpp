#include "Composite.h"

void Composite::Add(std::shared_ptr<Command> pCmd) {
	m_Commands.push_back(pCmd) ;
}

void Composite::Execute() {
	for(auto cmd : m_Commands) {
		cmd->Execute() ;
	}
}
