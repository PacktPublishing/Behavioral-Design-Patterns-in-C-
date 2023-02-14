#include "OnlineHelp.h"

void OnlineHelp::ShowHelp(const std::string& topic) {
	if(topic == "settings") {
		std::cout << "[OnlineHelp] Information on more settings \n" ;
	}else {
		HelpHandler::ShowHelp(topic) ;
	}
}
