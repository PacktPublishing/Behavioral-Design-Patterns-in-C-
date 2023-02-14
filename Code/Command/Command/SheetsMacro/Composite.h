#pragma once
#include <memory>
#include <vector>

#include "Command.h"
class Composite :
    public Command
{
	std::vector<std::shared_ptr<Command>> m_Commands{} ;
public:
	void Add(std::shared_ptr<Command> pCmd) ;

	void Execute() override;
};

