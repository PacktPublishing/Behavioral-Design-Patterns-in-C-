#pragma once
#include "Point.h"
#include "Shape.h"
#include "Visitable.h"

class Line :
    public Visitable<Line>
{
	Point m_Start{} ;
	Point m_End{} ;
public:
	Line()=default ;
	void SetStart(const Point &start) ;
	void SetEnd(const Point &end) ;
	Line(const Point& start, const Point& end);
	const Point & GetStart()const ;
	const Point & GetEnd()const ;
};

