#include "ConcreteStrategyA.h"
#include "ConcreteStrategyB.h"
#include "Context.h"

int main() {
	ConcreteStrategyA ca{} ;
	ConcreteStrategyB cb{} ;
	Context context ;
	context.SetStrategy(&ca) ;
	context.ContextInterface() ;
}
