#pragma once
#include "Operation.h"
class Area :
    public Operation
{
	float m_CircleArea{} ;
public:
	void VisitCircle(Circle* pCircle) override;
	void VisitLine(Line* pLine) override;
	float GetCircleArea()const ;
};

