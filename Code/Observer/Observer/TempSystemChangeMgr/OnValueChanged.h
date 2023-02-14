#pragma once
#include <string_view>
class Sensor;
class OnValueChanged
{
public:
	virtual void Notify(Sensor *pSubject) = 0 ;
	virtual ~OnValueChanged()=default ;
};

