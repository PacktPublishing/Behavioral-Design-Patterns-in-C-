#pragma once
#include "Command.h"
class Application;

class CommandDisplay :
    public Command
{
	Application *m_pApp{} ;
public:
	CommandDisplay(Application* mPApp)
		: m_pApp{mPApp} {
	}

	void Execute(int id) override;
	void Undo() override;
	void Redo() override;
};

