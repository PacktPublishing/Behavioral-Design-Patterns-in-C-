#pragma once
class OnValueChanged
{
public:
	virtual void Notify(float value) = 0 ;
	virtual ~OnValueChanged()=default ;
};

