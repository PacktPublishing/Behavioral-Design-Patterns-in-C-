#pragma once
class Visitor ;
class Element
{
public:
	virtual void Accept(Visitor *pVisitor) = 0 ;
	virtual ~Element() = default ;
};

