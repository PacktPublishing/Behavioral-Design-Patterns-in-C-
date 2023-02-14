#include <iostream>

#include "Application.h"
#include "Menu.h"

int main() {
	Application app{} ;
	Menu menu{&app} ;
	menu.Run() ;
	
	//app.AddText("Umar") ;
	//app.AddText("Majid") ;
	//app.AddText("Lone") ;
	//app.InsertText(0, "Mr\n") ;
	//app.SetColor(Color::BLUE) ;
	//app.Display() ;
	//app.RemoveText(0,5) ;
	//app.SetBold(true) ;
	//app.SetColor(Color::GREEN) ;
	//app.Display() ;


	
}
