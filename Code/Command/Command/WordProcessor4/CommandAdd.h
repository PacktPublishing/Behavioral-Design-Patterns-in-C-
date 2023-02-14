#pragma once
#include <string>

#include "Command.h"
class Application;

class CommandAdd :
    public Command
{
	Application *m_pApp{} ;
	std::string m_Text{} ;
public:
	CommandAdd(Application* mPApp);
	void Execute(int id) override;
	void Undo() override;
	void Redo() override;
};

