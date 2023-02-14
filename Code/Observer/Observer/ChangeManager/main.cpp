#include <iostream>

#include "Billboard.h"
#include "Recorder.h"
#include "SimpleDisplay.h"
#include "TemperatureSensor.h"
#include "ChangeManager.h"
#include "WindSpeedSensor.h"

int main() {
	ChangeManager mgr{} ;
	TemperatureSensor tempSensor{&mgr} ;
	WindSpeedSensor windSensor{&mgr} ;
	Billboard bb;
	SimpleDisplay sd ;
	Recorder rd ;

	mgr.Register(&tempSensor, &bb) ;
	mgr.Register(&tempSensor, &sd) ;
	mgr.Register(&tempSensor, &rd) ;

	mgr.Register(&windSensor, &bb) ;

	std::cout <<"Temperature changing...\n" ;
	tempSensor.SetTemp(21.3f) ;
	std::cout << "Wind speed changing...\n" ;
	windSensor.SetSpeed(50) ;
}
