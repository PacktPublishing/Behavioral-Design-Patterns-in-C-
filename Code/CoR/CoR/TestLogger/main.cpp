#include <iostream>
#include <string>
#include <vector>



#include "Application.h"
#include "ConsoleLogger.h"
#include "DbLogger.h"
#include "FileLogger.h"
std::vector<Logger*> loggers{};
int main() {
	
	Application app ;
	app.RegisterLogger("FILE", new FileLogger{"applog.txt"}) ;
	app.RegisterLogger("DB", new DbLogger{nullptr}) ;
	app.OnStart() ;
	app.OnUserLogged() ;
	app.OnDataRequested() ;
	app.OnExit() ;
	//FileLogger fl{nullptr, "mylog.txt" } ;
	//DbLogger dl{&fl} ;
	//ConsoleLogger cl{&dl} ;

	////loggers.push_back(&cl) ;
	//Logger *pLog = &cl ;
	//
	//pLog->Log("Application started", "CONSOLE") ;
	//pLog->Log("User did not specify the parameter", "DB") ;
	//pLog->Log("Failed to load the library", "DB") ;
	//pLog->Log("The library does not contain the entry point", "FILE") ;
	//pLog->Log("Application shutdown", "CONSOLE") ;

}

