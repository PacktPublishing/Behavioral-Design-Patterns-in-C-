#pragma once
#include <string>

class Server;

class Participant
{
	
	std::string m_Name{} ;
protected:
	Server *m_pServer{} ;
public:
	void RegisterServer(Server *pServer) {
		m_pServer = pServer ;
	}
	void SetName(std::string name) {
		m_Name = std::move(name) ;
	}
	const std::string & GetName()const {
		return m_Name ;
	}
	virtual void Send(const std::string &to, const std::string &message) = 0;
	virtual void Receive(const std::string &from, const std::string &message) = 0 ;
	virtual ~Participant()=default ;
};

