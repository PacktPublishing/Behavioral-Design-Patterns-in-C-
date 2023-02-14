#include "Context.h"
#include "State.h"
Context::Context(State* pState): m_pState(pState) {
}

void Context::Request() {
	m_pState = m_pState->Handle() ;
}
