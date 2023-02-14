#include "TransitionTable.h"

#include "OffState.h"
#include "OnState.h"
#include "YellowState.h"

State* TransitionTable::GetDefaultState() {
	return m_DefaultState ;
}

TransitionTable::TransitionTable() {
	m_DefaultState = new OffState{} ;
	auto offState = m_DefaultState ;
	auto onState = new OnState{} ;
	auto yellowState = new YellowState{} ;

	m_TransitionTable[offState] = {
		std::make_tuple("SwitchOff", offState),
		std::make_tuple("SwitchOn", onState),
		
	} ;
	m_TransitionTable[onState] = {
		std::make_tuple("SwitchOff", offState),
		std::make_tuple("SwitchOn", yellowState),
		
	} ;

	m_TransitionTable[yellowState] = {
		std::make_tuple("SwitchOff", offState),
		std::make_tuple("SwitchOn", onState),
		
	} ;
	/*
	 * key		event		next_state
	 * State *	std::string	State *
	 */
}

TransitionTable::~TransitionTable() {
	for(auto state : m_TransitionTable) {
		delete state.first ;
	}
}

State* TransitionTable::DoTransition(State* pCurrentState, const std::string& event) {
	auto &vec_action = m_TransitionTable[pCurrentState]	 ;
	auto found = std::find_if(vec_action.begin(), vec_action.end(),
		[&event](const ActionInfo & actionInfo) {
			return std::get<0>(actionInfo) == event ;
		}) ;
	if(found == vec_action.end()) {
		throw std::runtime_error{"Could not locate the event"} ;
	}
	return std::get<1>(*found) ;
}
