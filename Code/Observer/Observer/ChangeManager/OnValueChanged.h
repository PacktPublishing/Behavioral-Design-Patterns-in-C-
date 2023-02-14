#pragma once
class Sensor;

class OnValueChanged
{
public:
	virtual void Notify(Sensor *pSensor) = 0 ;
	virtual ~OnValueChanged()=default ;
};

