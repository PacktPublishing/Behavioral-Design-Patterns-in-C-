#include "TransitionTable.h"

#include <iostream>


const std::string & TransitionTable::DoTransition(const std::string &currentState,
	const std::string& event) {
	auto &actionInfo = m_TransitionTable[std::pair{currentState, event}] ;
	auto &[func, next_state] = actionInfo ;
	if(func) {
		func() ;
	}else {
		std::cout << "Nothing to do\n" ;
	}
	return next_state ;
}

void TransitionTable::AddEntry(const StateInfo& stateInfo, const ActionInfo& actionInfo) {
	m_TransitionTable.insert(std::pair{stateInfo, actionInfo})	 ;
}
