#include "LocalHelp.h"

void LocalHelp::ShowHelp(const std::string& topic) {
	if (topic == "saveptions") {
		std::cout << "[LocalHelp] Save options\n";
	}
	else {
		HelpHandler::ShowHelp(topic);
	}
}
template void Foo(int) ;