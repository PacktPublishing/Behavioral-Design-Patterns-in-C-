#include <iostream>
#include <vector>


#include "Alarm.h"
#include "HeavyGunner.h"
#include "Soldier.h"
#include "Tank.h"


int main() {

	Alarm alarm{} ;
	Soldier soldier{&alarm} ;
	HeavyGunner heavyGunner{&alarm} ;
	Tank tank{&alarm} ;

	alarm.SetAlarmOn() ;

} 

