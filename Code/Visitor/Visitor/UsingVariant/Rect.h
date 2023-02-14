#pragma once
#include "Shape.h"
#include "Point.h"

class Rect :
    public Shape
{
	Point m_TopLeft{} ;
	Point m_BottomRight{} ;
public:
	Rect() = default ;
	Rect(const Point& topLeft, const Point& bottomRight);
	const Point & GetTopLeft()const ;
	const Point & GetBottomRight()const ;
	void SetTopLeft(const Point & topLeft) ;
	void SetBottomRight(const Point & bottomRight) ;
};

