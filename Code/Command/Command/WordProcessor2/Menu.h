#pragma once
#include <functional>
#include <map>
#include <string>
class InputHandler ;
class Menu
{
	using Callback = std::function<void()> ;
	using CallbackInfo= std::tuple<std::string, Callback> ;
	std::map<int, CallbackInfo> m_InputTable{} ;
	[[nodiscard]]
	std::map<int, CallbackInfo>::iterator InvokeFirstHandler() ;
	void DisplayMenu(std::map<int, CallbackInfo>::iterator iter) ;
	[[nodiscard]]
	bool Input();
public:

	void Init(int choice, const std::string & menuText, Callback callback) ;
	void Run() ;
};

void Message(const std::string &text) ;