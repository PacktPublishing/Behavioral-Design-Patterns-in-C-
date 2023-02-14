#include "ConcreteStateA.h"
#include "Context.h"

int main() {
	ConcreteStateA state_a{} ;
	Context ctx{&state_a} ;
	ctx.Request();
	ctx.Request();
	ctx.Request();
}
