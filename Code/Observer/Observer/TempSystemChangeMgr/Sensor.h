#pragma once
#include <any>
#include <string>
class ChangeManager;
class OnValueChanged;

class Sensor
{
	ChangeManager *m_pChangeManager{} ;
public:
	Sensor(ChangeManager* mPChangeManager);
	void Register(OnValueChanged *p) ;
	void Deregister(OnValueChanged *p);
	void Notify() ;
	virtual std::any GetValue() = 0 ;
	virtual std::string GetType()const = 0 ;
	virtual ~Sensor() = default ;
};

