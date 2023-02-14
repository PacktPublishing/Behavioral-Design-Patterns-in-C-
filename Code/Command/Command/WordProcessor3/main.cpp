#include <iostream>

#include "Application.h"
#include "Menu.h"
int main() {
	Application app{} ;
	Menu menu ;
	menu.Init(0, "",			&app ) ;
	menu.Init(1, "Add",			&app ) ;
	menu.Init(2, "Insert",		&app ) ;
	menu.Init(3, "Overwrite",	&app ) ;
	menu.Init(4, "Remove",		&app ) ;
	menu.Init(5, "SetColor",	&app ) ;
	menu.Init(6, "SetBold",		&app ) ;
	menu.Init(7, "Undo",		&app ) ;

	menu.Run() ;		

	
}
