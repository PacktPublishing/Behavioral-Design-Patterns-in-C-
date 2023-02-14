#include <iostream>
#include <string>


#include "ConsoleLogger.h"
#include "DbLogger.h"
#include "FileLogger.h"

int main() {
	FileLogger fl{nullptr, "mylog.txt" } ;
	DbLogger dl{&fl} ;
	ConsoleLogger cl{&dl} ;

	Logger *pLog = &cl ;
	
	pLog->Log("Application started", "CONSOLE") ;
	pLog->Log("User did not specify the parameter", "DB") ;
	pLog->Log("Failed to load the library", "DB") ;
	pLog->Log("The library does not contain the entry point", "FILE") ;
	pLog->Log("Application shutdown", "CONSOLE") ;

}
