#include "Menu.h"

#include <iostream>
#include "Application.h"

void Message(const std::string &text) {
	std::cout << text << std::endl;
	system("pause") ;
	system("cls") ;
}


std::map<int, Menu::CallbackInfo>::iterator Menu::InvokeFirstHandler() {
	auto iter = m_InputTable.begin();
	if (iter->first == 0) {
		std::get<1>(iter->second)();
		++iter;
	}
	return iter;
}

void Menu::Init(int choice, const std::string& menuText, Callback callback) {
	m_InputTable[choice] = std::make_tuple(menuText, callback) ;
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
		std::get<1>(m_InputTable[choice])() ;
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
	Message("=== Application terminated === ") ;
}
