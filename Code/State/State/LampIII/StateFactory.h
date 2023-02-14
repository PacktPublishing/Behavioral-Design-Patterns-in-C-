#pragma once
#include <string_view>
class State;

class StateFactory
{
public:
	static State * GetState(std::string_view stateType) ;
};

