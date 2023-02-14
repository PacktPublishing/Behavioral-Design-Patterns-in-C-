#pragma once
class Command
{
public:
	virtual void Execute(int id) = 0 ;
	virtual ~Command() = default ;
};

