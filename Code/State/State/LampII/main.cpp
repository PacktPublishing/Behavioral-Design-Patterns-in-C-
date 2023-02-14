#include <crtdbg.h>
#include <cstdlib>

#include "Lamp.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF| _CRTDBG_LEAK_CHECK_DF) ;
	Lamp lamp{} ;
	lamp.SwitchOn() ;
	system("pause") ;
	lamp.SwitchOn() ;
	system("pause") ;
	lamp.SwitchOff() ;
	system("pause") ;
	lamp.SwitchOff() ;
	system("pause") ;
}
 