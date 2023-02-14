#pragma once
#include "Command.h"
class Application;

class CommandBold :
    public Command
{
	Application *m_pApp{} ;
	bool m_Bold{} ;
public:
	CommandBold(Application* mPApp)
		: m_pApp{mPApp} {
	}

	void Execute(int id) override;

	void Undo() override;
	void Redo() override;
};

