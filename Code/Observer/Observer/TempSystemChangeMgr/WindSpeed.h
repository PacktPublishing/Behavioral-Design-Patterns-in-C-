#pragma once
#include "Sensor.h"
class WindSpeed :
    public Sensor
{
	using Sensor::Sensor ;
	float m_Speed{} ;
public:
	void SetSpeed(float speed) ;
	std::string GetType() const override;
	std::any GetValue() override;
};

