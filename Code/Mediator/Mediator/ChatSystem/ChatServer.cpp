#include "ChatServer.h"

#include <iostream>
#include "Participant.h"
void ChatServer::SendMessage(const std::string& from, const std::string& to, const std::string& message) {
	if(to.empty()) {
		std::cout << "\n===== BROADCAST =====\n" ;
		for(const auto &participant : m_Participants) {
			if(participant.first != from) {
				participant.second->Receive(from, message) ;
			}
		}
	}else {
		m_Participants[to]->Receive(from, message) ;
	}
}

void ChatServer::Register(const std::string& name, Participant* pParticipant) {
	for(const auto & participant : m_Participants) {
		participant.second->Receive(name, " joined the chat!") ;
	}
	m_Participants[name] = pParticipant ;
}

void ChatServer::Deregister(const std::string& name) {
	m_Participants.erase(name) ;
	for(const auto & participant : m_Participants) {
		participant.second->Receive(name, " left the chat!") ;
	}
}
