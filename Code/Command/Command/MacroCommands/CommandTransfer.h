#pragma once
#include "Command.h"
class CommandTransfer :
    public Command
{
	Command *m_pFrom{} ;
	Command *m_pTo{} ;
public:
	CommandTransfer(Command* mPFrom, Command* mPTo)
		: m_pFrom{mPFrom},
		  m_pTo{mPTo} {
	}

	void Execute() override;
	void Undo() override;
};

