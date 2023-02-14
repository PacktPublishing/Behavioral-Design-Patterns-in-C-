#include "StateFactory.h"


#include "OffState.h"
#include "OnState.h"
#include "YellowState.h"

State* StateFactory::GetState(std::string_view stateType) {
	static OnState on_state{} ;
	static OffState off_state{} ;
	static YellowState yellow_state{} ;
	if(stateType == "on_state") {
		return &on_state ;
	}else if(stateType == "off_state") {
		return &off_state ;
	}else if(stateType == "yellow_state") {
		return &yellow_state ;
	}
	throw std::runtime_error{"Unknown state requested"} ;
}
