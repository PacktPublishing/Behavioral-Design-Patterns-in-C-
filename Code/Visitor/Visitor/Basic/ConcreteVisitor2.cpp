#include "ConcreteVisitor2.h"

#include <iostream>
#include "ConcreteElementA.h"
#include "ConcreteElementB.h"
void ConcreteVisitor2::VisitConcreteElementA(ConcreteElementA* pA) {
	std::cout << "[ConcreteVisitor2] Visiting ConcreteElementA -> \t" ;
	pA->OperationA() ;
}

void ConcreteVisitor2::VisitConcreteElementB(ConcreteElementB* pB) {
	std::cout << "[ConcreteVisitor2] Visiting ConcreteElementB -> \t" ;
	pB->OperationB() ;
}
