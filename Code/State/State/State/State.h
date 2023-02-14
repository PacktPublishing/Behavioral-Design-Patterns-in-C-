#pragma once
class State
{
public:
	virtual State * Handle() = 0 ;
	virtual ~State() = default ;
};

