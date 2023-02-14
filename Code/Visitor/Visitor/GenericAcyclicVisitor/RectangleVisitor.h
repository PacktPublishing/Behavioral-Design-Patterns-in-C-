#pragma once
class Rect;

class RectangleVisitor
{
public:
	virtual void VisitRectangle(Rect *pRect) = 0 ;
	virtual ~RectangleVisitor()=default ;
};

