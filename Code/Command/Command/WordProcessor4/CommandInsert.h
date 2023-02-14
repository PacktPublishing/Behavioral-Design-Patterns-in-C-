#pragma once
#include "Command.h"
class Application;

class CommandInsert :
    public Command
{
	Application *m_pApp{} ;
	size_t m_Start{} ;
	std::string m_Text{} ;
public:
	CommandInsert(Application* mPApp);

	void Execute(int id) override;
	void Undo() override;
	void Redo() override;
};

