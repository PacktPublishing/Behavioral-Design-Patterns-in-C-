#pragma once
#include "Command.h"
class CommandUndo :
    public Command
{
public:
	void Execute(int id) override;
	void Undo() override;
	void Redo() override;
};

