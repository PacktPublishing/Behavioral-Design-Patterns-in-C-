#pragma once
#include <functional>
#include <map>
#include <unordered_map>
using StateInfo = std::pair<std::string, std::string> ;
using ActionInfo = std::pair<std::function<void()>, std::string> ;
class TransitionTable
{
	std::map<StateInfo, ActionInfo> m_TransitionTable{} ;
public:
	const std::string & DoTransition(const std::string & currentState, const std::string & event) ;
	void AddEntry(const StateInfo &stateInfo, const ActionInfo &actionInfo) ;
};

