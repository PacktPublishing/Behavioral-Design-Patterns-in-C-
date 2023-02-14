#pragma once
#include <functional>
#include <map>
#include <string>

class Command ;
class InputHandler ;
class Menu
{
	using CallbackInfo= std::tuple<std::string, Command*> ;
	std::map<int, CallbackInfo> m_InputTable{} ;
	[[nodiscard]]
	std::map<int, CallbackInfo>::iterator InvokeFirstHandler() ;
	void DisplayMenu(std::map<int, CallbackInfo>::iterator iter) ;
	[[nodiscard]]
	bool Input();
public:

	void Init(int choice, const std::string & menuText, Command* pCmd) ;
	void Run() ;
};

void Message(const std::string &text) ;