#pragma once
class Command;

class Invoker
{
	Command *m_pCommand{} ;
public:
	void SetCommand(Command *pCmd);
	void Invoke() ;
};

