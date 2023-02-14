#include <iostream>

#include "Application.h"
#include "Menu.h"
int main() {
	Application app{} ;
	Menu menu{} ;
	menu.Init(0, "",			std::bind(&Application::Display,		&app) ) ;
	menu.Init(1, "Add",			std::bind(&Application::InputAdd,		&app) ) ;
	menu.Init(2, "Insert",		std::bind(&Application::InputInsert,	&app) ) ;
	menu.Init(3, "Overwrite",	std::bind(&Application::InputOverwrite,	&app) ) ;
	menu.Init(4, "Remove",		std::bind(&Application::InputRemove,	&app) ) ;
	menu.Init(5, "SetColor",	std::bind(&Application::InputSetColor,	&app) ) ;
	menu.Init(6, "SetBold",		std::bind(&Application::InputSetBold,	&app) ) ;

	menu.Run() ;
	
}
