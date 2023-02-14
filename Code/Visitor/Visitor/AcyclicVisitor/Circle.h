#pragma once
#include "Point.h"
#include "Shape.h"
class Circle :
    public Shape
{
	Point m_Position{} ;
	int m_Radius{} ;

public:
	Circle()=default ;
	Circle(const Point& position, int radius);
	void SetPosition(const Point &position) ;
	void SetRadius(int radius) ;
	const Point & GetPosition()const ;
	int GetRadius()const ;
	void Accept(Operation* pOperation) override;
};

