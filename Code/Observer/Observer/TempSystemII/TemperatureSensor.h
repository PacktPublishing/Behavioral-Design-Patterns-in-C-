#pragma once
#include <list>
#include <unordered_map>

class OnValueChanged;
enum class Frequency{LOW, HIGH};
class TemperatureSensor
{
	std::unordered_map<Frequency, std::list<OnValueChanged*>> m_Subscribers{} ;
	float m_Temperature{} ;
	float m_Change{} ;
	void Notify(std::list<OnValueChanged*> subscribers) ;
public:
	void Register(Frequency pr, OnValueChanged *p) ;
	void Deregister(Frequency pr, OnValueChanged *p) ;
	void Notify(float value) ;
	void SetTemp(float value) ;
};

