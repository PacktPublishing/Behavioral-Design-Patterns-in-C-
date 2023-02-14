#pragma once
#include "CircleVisitor.h"
#include "Operation.h"
class Area :
    public Operation, public CircleVisitor
{
	float m_CircleArea{} ;
public:
	void VisitCircle(Circle* pCircle) override;
	float GetCircleArea()const ;
};

