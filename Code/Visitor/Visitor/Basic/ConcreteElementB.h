#pragma once
#include "Element.h"
class ConcreteElementB :
    public Element
{
public:
	void OperationB() ;

	void Accept(Visitor* pVisitor) override;
};

