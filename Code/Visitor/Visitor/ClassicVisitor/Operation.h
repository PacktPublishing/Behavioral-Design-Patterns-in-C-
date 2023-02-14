#pragma once
class Line;
class Circle;

class Operation {
public:
	virtual void VisitCircle(Circle *pCircle) = 0 ;
	virtual void VisitLine(Line *pLine) = 0 ;
};
