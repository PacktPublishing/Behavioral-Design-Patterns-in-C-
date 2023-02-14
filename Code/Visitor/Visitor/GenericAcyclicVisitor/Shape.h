#pragma once
class Operation ;
class Shape
{
public:
	virtual void Accept(Operation *pOperation) = 0 ;
	virtual ~Shape() = default ;
};

