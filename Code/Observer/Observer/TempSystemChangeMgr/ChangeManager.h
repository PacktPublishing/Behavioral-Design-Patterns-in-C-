#pragma once
#include <unordered_map>
class OnValueChanged;
class Sensor ;
class ChangeManager
{
public:
	virtual void Register(Sensor *pSubject, OnValueChanged *pChanged) = 0 ;
	virtual void Deregister(Sensor *pSubject, OnValueChanged *pChanged) = 0 ;
	virtual void Notify(Sensor *pSubject) = 0 ;
	virtual ~ChangeManager()=default ;
};

