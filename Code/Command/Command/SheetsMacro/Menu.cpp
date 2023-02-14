#include "Menu.h"

#include <iostream>
#include "Command.h"

void Message(const std::string &text) {
	std::cout << "\n------ " << text << " ------" << std::endl;
	system("pause") ;
	system("cls") ;
}


std::map<int, Menu::CallbackInfo>::iterator Menu::InvokeFirstHandler() {
	auto iter = m_InputTable.begin();
	if (iter->first == 0) {
		std::get<1>(iter->second)->Execute();
		++iter;
	}
	return iter;
}

void Menu::Init(int choice, const std::string& menuText,  std::shared_ptr<Command> pCmd) {
	m_InputTable[choice] = std::make_tuple(menuText, pCmd) ;
}

void Menu::DisplayMenu(std::map<int, CallbackInfo>::iterator iter) {
	std::cout << "\n----------------------------------\n" ;
	for(;iter != m_InputTable.end() ; ++iter){
		std::cout <<iter->first << ". " << std::get<0>(iter->second) << "\n" ;
	}
}

bool Menu::Input() {
	size_t choice{} ;
	std::cout << "Your choice (0 to exit)?" ;
	std::cin >> choice ;
	if(choice == 0) {
		return false ;
	}
	if(choice > m_InputTable.size()) {
		Message("Unknown option.Try again!") ;
	}
	else if(choice >= 1 && choice <= m_InputTable.size()) {
		std::get<1>(m_InputTable[choice])->Execute() ;
		Message("Operation completed") ;
	}
	return true ;
}
void Menu::Run() {
	while(true) {
		const auto iter = InvokeFirstHandler() ;
		DisplayMenu(iter);
		if(!Input()) {
			break ;
		}
	}
	Message("Application terminated") ;
}
