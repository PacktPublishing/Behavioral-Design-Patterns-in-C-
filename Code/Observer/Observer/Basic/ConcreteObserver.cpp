#include "ConcreteObserver.h"

#include <iostream>

#include "ConcreteSubject.h"
ConcreteObserver::ConcreteObserver(ConcreteSubject* mPSubject): m_pSubject{mPSubject} {
}

void ConcreteObserver::Update() {
	std::cout
		<< "[ConcreteObserver] Received notification. State is:"
		<< m_pSubject->GetState() << '\n' ;
}
