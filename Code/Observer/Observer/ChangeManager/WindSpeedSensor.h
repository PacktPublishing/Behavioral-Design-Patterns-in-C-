#pragma once
#include "Sensor.h"
class ChangeManager;

class WindSpeedSensor :
    public Sensor
{
	float m_Speed ;
	ChangeManager *m_pMgr{} ;

public:
	WindSpeedSensor(ChangeManager* pMgr);

	float GetValue() const override;
	void Notify() override;
	void SetSpeed(float speed); 
};

