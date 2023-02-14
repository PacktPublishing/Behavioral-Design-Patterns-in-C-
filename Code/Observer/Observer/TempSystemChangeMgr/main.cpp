#include "BillBoard.h"
#include "Display.h"
#include "Recorder.h"
#include "TemperatureSensor.h"
#include "SimpleChangeManager.h"
#include "WindSpeed.h"

int main() {
	SimpleChangeManager cm{} ;
	TemperatureSensor sensor{&cm} ;
	WindSpeed ws{&cm} ;
	BillBoard bb;
	Display dy ;
	Recorder re ;

	cm.Register(&sensor, &bb) ;
	cm.Register(&sensor, &dy) ;
	cm.Register(&sensor, &re) ;

	cm.Register(&ws, &bb) ;
	cm.Register(&ws,&dy) ;

	sensor.SetTemp(21.3f) ;
	sensor.SetTemp(21.9f) ;

	ws.SetSpeed(15.0f) ;
}
