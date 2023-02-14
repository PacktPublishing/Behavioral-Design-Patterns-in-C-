#pragma once
class Sensor
{
public:
	virtual float GetValue()const = 0 ;
	virtual void Notify() = 0 ;
	virtual ~Sensor()=default ;
};

