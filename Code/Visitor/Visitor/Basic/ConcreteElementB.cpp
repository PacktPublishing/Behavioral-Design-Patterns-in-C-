#include "ConcreteElementB.h"

#include <iostream>
#include "Visitor.h"
void ConcreteElementB::OperationB() {
	std::cout << "[ConcreteElementB] Invoked operation B\n" ;
}

void ConcreteElementB::Accept(Visitor* pVisitor) {
	pVisitor->VisitConcreteElementB(this) ;
}
