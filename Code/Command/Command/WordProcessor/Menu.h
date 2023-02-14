#pragma once
#include <map>
class Application;

class Menu
{
	Application *m_pApp{} ;
	std::map<int, void *> m_InputTable{} ;
public:
	Menu(Application *app) ;
	void Init(int choice, void *pCallback) ;
	void Run() ;
	void AddText() ;
	void Overwrite() ;
	void RemoveText() ;
	void SetColor() ;
	void SetBold() ;
	void InsertText() ;
};

