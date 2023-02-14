#pragma once
#include "ChangeManager.h"
class SimpleChangeManager :
    public ChangeManager
{
	std::unordered_map<Sensor *, std::list<OnValueChanged*>> m_Mapping{} ;
public:
	void Deregister(Sensor* pSubject, OnValueChanged* pChanged) override;
	void Notify(Sensor* pSubject) override;
	void Register(Sensor* pSubject, OnValueChanged* pChanged) override;
};

