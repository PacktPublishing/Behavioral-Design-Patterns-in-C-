#pragma once
#include <list>


#include "Sensor.h"

class ChangeManager;
class OnValueChanged;

class TemperatureSensor : public Sensor
{
private:
	ChangeManager *m_pMgr{} ;
	float m_Temperature{} ;
public:
	TemperatureSensor(ChangeManager* pMgr);
	void Notify()override ;
	void SetTemp(float value) ;

	float GetValue() const override;
};

