#include "ConcreteVisitor1.h"

#include <iostream>

#include "ConcreteElementA.h"
#include "ConcreteElementB.h"

void ConcreteVisitor1::VisitConcreteElementA(ConcreteElementA* pA) {
	std::cout << "[ConcreteVisitor1] Visiting ConcreteElementA -> \t" ;
	pA->OperationA() ;
}

void ConcreteVisitor1::VisitConcreteElementB(ConcreteElementB* pB) {
	std::cout << "[ConcreteVisitor1] Visiting ConcreteElementB -> \t" ;
	pB->OperationB() ;
}
