#pragma once
#include <string>

#include "Command.h"
class Application;

class CommandOverwrite :
    public Command
{
	Application *m_pApp{} ;
	size_t m_Start ;
	std::string m_Text{} ;
public:
	CommandOverwrite(Application* mPApp)
		: m_pApp{mPApp} {
	}

	void Execute(int id) override;
	void Undo() override;
	void Redo() override;
};

