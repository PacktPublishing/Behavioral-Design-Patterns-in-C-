#pragma once
#include "Visitor.h"
class ConcreteVisitor1 :
    public Visitor
{

public:
	void VisitConcreteElementA(ConcreteElementA* pA) override;
	void VisitConcreteElementB(ConcreteElementB* pB) override;
};

