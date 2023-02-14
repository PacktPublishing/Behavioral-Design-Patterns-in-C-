#include <cstdlib>

#include "Lamp.h"

int main() {
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
