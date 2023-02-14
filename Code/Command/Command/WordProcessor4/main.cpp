#include <iostream>

#include "Application.h"
#include "CommandAdd.h"
#include "CommandBold.h"
#include "CommandColor.h"
#include "CommandDisplay.h"
#include "CommandInsert.h"
#include "CommandOverwrite.h"
#include "CommandRedo.h"
#include "CommandRemove.h"
#include "CommandUndo.h"
#include "Menu.h"
int main() {
	//std::string str = "C++ Java" ;
	//str.erase(4, 4) ;
	//return 0 ;
	Application app{} ;
	
	std::shared_ptr<CommandAdd>       cmdAdd       { new CommandAdd { &app } } ;
	std::shared_ptr<CommandInsert>    cmdInsert    { new CommandInsert { &app } } ;
	std::shared_ptr<CommandOverwrite> cmdOverwrite { new CommandOverwrite { &app } } ;
	std::shared_ptr<CommandRemove>    cmdRemove    { new CommandRemove { &app } } ;
	std::shared_ptr<CommandBold>      cmdBold      { new CommandBold { &app } } ;
	std::shared_ptr<CommandColor>     cmdColor     { new CommandColor { &app } } ;
	std::shared_ptr<CommandDisplay>   cmdDisplay   { new CommandDisplay { &app } } ;
	std::shared_ptr<CommandUndo>      cmdUndo	   { new CommandUndo { } } ;
	std::shared_ptr<CommandRedo>      cmdRedo      { new CommandRedo { } } ;
	Menu menu ;
	menu.Init(0, "",			cmdDisplay.get() ) ;
	menu.Init(1, "Add",			cmdAdd.get() ) ;
	menu.Init(2, "Insert",		cmdInsert.get() ) ;
	menu.Init(3, "Overwrite",	cmdOverwrite.get() ) ;
	menu.Init(4, "Remove",		cmdRemove.get() ) ;
	menu.Init(5, "SetColor",	cmdColor.get() ) ;
	menu.Init(6, "SetBold",		cmdBold.get() ) ;
	menu.Init(7, "Undo",		cmdUndo.get() ) ;
	menu.Init(8, "Redo",		cmdRedo.get() ) ;

	menu.Run() ;		

	
}
