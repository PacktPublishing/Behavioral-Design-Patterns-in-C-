#pragma once
#include <list>
#include <unordered_map>

class OnValueChanged;
enum class TemperatureChange {SMALL, LARGE};
class TemperatureSensor
{
	std::unordered_map<TemperatureChange, std::list<OnValueChanged *>> m_Subscribers{} ;
	float m_Temperature{} ;
	float m_Change{} ;
	void Notify(TemperatureChange tc) ;
public:
	void Register(TemperatureChange tc, OnValueChanged *p) ;
	void Deregister(TemperatureChange tc, OnValueChanged *p) ;
	void Notify(float value) ;
	void SetTemp(float value) ;
};

