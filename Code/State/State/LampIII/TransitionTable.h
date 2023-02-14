#pragma once
#include <unordered_map>
class State ;
using ActionInfo = std::tuple<std::string, State *> ;
class TransitionTable
{
	std::unordered_map<State *, std::vector<ActionInfo>> m_TransitionTable{} ;
	State *m_DefaultState{} ;
public:
	State * GetDefaultState() ;
	TransitionTable();
	~TransitionTable();
	State * DoTransition(State *pCurrentState, const std::string & event) ;
};

