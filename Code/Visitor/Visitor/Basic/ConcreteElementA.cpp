#include "ConcreteElementA.h"

#include <iostream>
#include "Visitor.h"
void ConcreteElementA::OperationA() {
	std::cout << "[ConcreteElementA] Operation A invoked\n" ;
}

void ConcreteElementA::Accept(Visitor* pVisitor) {
	pVisitor->VisitConcreteElementA(this) ;
}
