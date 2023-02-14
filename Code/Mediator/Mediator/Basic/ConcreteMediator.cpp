#include "ConcreteMediator.h"
#include "Colleague.h" 
void ConcreteMediator::SetColleagues(Colleague* pC1, Colleague* pC2) {
	m_pColleague1 = pC1 ;
	m_pColleague2 = pC2 ;
}

void ConcreteMediator::OnInvoke(Colleague* pColleague) {
	auto type = pColleague->GetType() ;
	if(type == "cc1") {
		m_pColleague2->SendMessageA() ;
	}else if(type == "cc2") {
		m_pColleague1->SendMessageB() ;
	}
}
