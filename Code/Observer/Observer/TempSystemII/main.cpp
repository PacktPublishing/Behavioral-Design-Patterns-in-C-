#include "BillBoard.h"
#include "Display.h"
#include "Recorder.h"
#include "TemperatureSensor.h"

int main() {
	TemperatureSensor sensor{} ;
	BillBoard bb;
	Display dy ;
	Recorder re ;

	sensor.Register(Frequency::LOW, &bb) ;
	sensor.Register(Frequency::LOW, &dy) ;
	sensor.Register(Frequency::HIGH, &re) ;

	sensor.SetTemp(21.3f) ;
	sensor.SetTemp(21.6f) ;
	sensor.SetTemp(21.9f) ;
	sensor.SetTemp(22.8f) ;
}
