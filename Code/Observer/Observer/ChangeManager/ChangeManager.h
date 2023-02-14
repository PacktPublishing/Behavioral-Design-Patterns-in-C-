#pragma once
#include <unordered_map>

class OnValueChanged;
class Sensor;

class ChangeManager
{
	std::unordered_map<Sensor *, std::list<OnValueChanged*>> m_Mapping{} ;
public:
	void Register(Sensor *pSensor, OnValueChanged *pValueChanged) ;
	void DeRegister(Sensor *pSensor, OnValueChanged *pValueChanged) ;
	void Notify(Sensor *pSensor) ;
};

