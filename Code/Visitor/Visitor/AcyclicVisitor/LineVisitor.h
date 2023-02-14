#pragma once
class Line;

class LineVisitor
{
public:
	virtual void VisitLine(Line *line) = 0 ;
	virtual ~LineVisitor()=default ;
};

