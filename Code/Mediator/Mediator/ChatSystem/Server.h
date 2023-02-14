#pragma once
#include <string>

class Participant;

class Server
{
public:
	virtual void SendMessage(const std::string &from, 
		const std::string &to, const std::string &message) = 0 ;
	virtual void Register(const std::string &name, Participant *pParticipant) = 0 ;
	virtual void Deregister(const std::string &name) = 0 ;
	virtual ~Server()=default ;
};

