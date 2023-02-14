#pragma once
#include "Operation.h"
#include "OperationVisitor.h"
#include "Circle.h"

class Area :
    public Operation, public OperationVisitor<Circle>
{
	float m_CircleArea{} ;
public:
	void Visit(Circle* pCircle) override;
	float GetCircleArea()const ;
};

