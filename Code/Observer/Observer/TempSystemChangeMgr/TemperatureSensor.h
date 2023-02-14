#pragma once
#include <list>

#include "Sensor.h"

class OnValueChanged;

class TemperatureSensor : public Sensor
{
	float m_Temperature{} ;
	using Sensor::Sensor ;
public:
	void SetTemp(float value) ;
	std::any GetValue() override;
	std::string GetType() const override;
};

