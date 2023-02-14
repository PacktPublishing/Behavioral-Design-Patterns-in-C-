#include "Client.h"
#include "Handler.h"
void Client::SetHandler(Handler* pHandler) {
	m_pHandler = pHandler ;
}

void Client::Request() {
	m_pHandler->HandleRequest() ;
}
