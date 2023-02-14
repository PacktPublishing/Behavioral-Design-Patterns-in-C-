#pragma once
#include "Command.h"
class CommandRedo :
    public Command
{

public:
	void Execute(int id) override;
	void Redo() override;
	void Undo() override;
};

