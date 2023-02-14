#include "QuickHelp.h"

void QuickHelp::ShowHelp(const std::string&topic) {
	if(topic == "color") {
		std::cout << "[Quickhelp] Showing color help\n" ;
	}else {
		HelpHandler::ShowHelp(topic) ;
	}
}
