#include <vector>

#include "ConcreteElementA.h"
#include "ConcreteElementB.h"
#include "ConcreteVisitor1.h"
#include "ConcreteVisitor2.h"

int main() {
	std::vector<Element*> elements{
		new ConcreteElementA{},
		new ConcreteElementB{}
	} ;
	ConcreteVisitor1 cv1{} ;
	ConcreteVisitor2 cv2{} ;
	for(auto element : elements) {
		/*if(auto elem = dynamic_cast<ConcreteElementA*>(element)) {
			elem->OperationA() ;
		}else if(auto elem = dynamic_cast<ConcreteElementB*>(element)) {
			elem->OperationB() ;
		}*/
		element->Accept(&cv2) ;
	}
}
