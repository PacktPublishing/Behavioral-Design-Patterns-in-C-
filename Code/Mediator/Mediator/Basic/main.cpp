#include "ConcreteColleague1.h"
#include "ConcreteColleague2.h"
#include "ConcreteMediator.h"

int main() {
	ConcreteMediator cm{} ;
	ConcreteColleague1 c1{&cm} ;
	ConcreteColleague2 c2{&cm} ;

	cm.SetColleagues(&c1, &c2) ;

	c1.SendMessageA() ;

	c2.SendMessageB() ;
}
