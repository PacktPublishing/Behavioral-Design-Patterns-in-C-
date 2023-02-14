#include "Subject.h"
#include "Observer.h"
void Subject::Attach(Observer* pObserver) {
	m_Observers.push_back(pObserver) ;
}

void Subject::Detach(Observer* pObserver) {
	m_Observers.remove(pObserver) ;
}

void Subject::Notify() {
	for(auto observer : m_Observers) {
		observer->Update() ;
	}
}
