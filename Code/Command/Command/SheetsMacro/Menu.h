#pragma once
#include <functional>
#include <map>
#include <memory>
#include <string>

class Command ;
class InputHandler ;
class Menu
{
	using CallbackInfo= std::tuple<std::string, std::shared_ptr<Command>> ;
	std::map<int, CallbackInfo> m_InputTable{} ;
	[[nodiscard]]
	std::map<int, CallbackInfo>::iterator InvokeFirstHandler() ;
	void DisplayMenu(std::map<int, CallbackInfo>::iterator iter) ;
	[[nodiscard]]
	bool Input();
public:

	void Init(int choice, const std::string & menuText, std::shared_ptr<Command> pCmd) ;
	void Run() ;
};

void Message(const std::string &text) ;