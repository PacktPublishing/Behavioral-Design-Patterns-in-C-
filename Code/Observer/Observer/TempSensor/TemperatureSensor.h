#pragma once
#include <list>

class OnValueChanged;

class TemperatureSensor
{
	std::list<OnValueChanged *> m_Subscribers{} ;
	float m_Temperature{} ;
public:
	void Register(OnValueChanged *p) ;
	void Deregister(OnValueChanged *p) ;
	void Notify(float value) ;
	void SetTemp(float value) ;
};

