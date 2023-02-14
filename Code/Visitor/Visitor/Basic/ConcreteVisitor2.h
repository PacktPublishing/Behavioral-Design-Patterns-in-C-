#pragma once
#include "Visitor.h"
class ConcreteVisitor2 :
    public Visitor
{

public:
	void VisitConcreteElementA(ConcreteElementA* pA) override;
	void VisitConcreteElementB(ConcreteElementB* pB) override;
};

