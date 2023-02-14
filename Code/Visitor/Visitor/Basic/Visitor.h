#pragma once
class ConcreteElementB;
class ConcreteElementA;

class Visitor {
public:
	virtual void VisitConcreteElementA(ConcreteElementA *pA) = 0 ;
	virtual void VisitConcreteElementB(ConcreteElementB *pB) = 0 ;
};
