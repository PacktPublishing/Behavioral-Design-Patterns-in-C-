#pragma once
class Circle;

class CircleVisitor {
public:
	virtual void VisitCircle(Circle *circle) = 0 ;
	virtual ~CircleVisitor()=default ;
};
