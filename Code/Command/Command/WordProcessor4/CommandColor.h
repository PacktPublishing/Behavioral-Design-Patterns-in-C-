#pragma once
#include "Command.h"
#include "Console.h"
class Application;

class CommandColor :
    public Command
{
	Application *m_pApp{} ;
	Color m_Color{} ;
	void ReplaceColor();
public:
	CommandColor(Application* mPApp)
		: m_pApp{mPApp} {
	}
	void Execute(int id) override;
	void Undo() override;
	void Redo() override;
};

