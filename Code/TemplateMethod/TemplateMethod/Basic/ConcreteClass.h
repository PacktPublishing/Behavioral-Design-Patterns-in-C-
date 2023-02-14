#pragma once
#include "AbstractClass.h"
class ConcreteClass :
    public AbstractClass
{

public:
	void PrimitiveOperation1() override;
	void PrimitiveOperation2() override;
};

