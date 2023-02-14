#include "ConcreteAggregate.h"
#include <iostream>

int main() {
	ConcreteAggregate list{} ;
	list.Push(1) ;
	list.Push(2) ;
	list.Push(3) ;
	list.Push(4) ;
	list.Push(5) ;
	//list.Push(6) ;
	auto iter{list.CreateIterator()} ;
	while(!iter->IsDone()) {
		std::cout << iter->CurrentItem() << ' ' ;
		iter->Next() ;
	}
	delete iter ;
}
