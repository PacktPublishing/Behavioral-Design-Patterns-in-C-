#pragma once
#include "Element.h"
class ConcreteElementA :
    public Element
{
public:
	void OperationA() ;

	void Accept(Visitor* pVisitor) override;
};

