#include "Invoker.h"
#include "Receiver.h"

int main() {
	Receiver receiver{} ;
	Invoker invoker{} ;
	//invoker.SetCommand(&receiver) ;
	invoker.Invoke() ;
}
