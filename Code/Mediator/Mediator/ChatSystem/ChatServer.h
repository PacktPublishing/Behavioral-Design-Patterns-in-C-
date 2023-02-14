#pragma once
#include <unordered_map>

#include "Server.h"
class ChatServer :
    public Server
{
	std::unordered_map<std::string, Participant *> m_Participants{} ;
public:

	void SendMessage(const std::string& from, const std::string& to, const std::string& message) override;
	void Register(const std::string& name, Participant* pParticipant) override;
	void Deregister(const std::string& name) override;
};

