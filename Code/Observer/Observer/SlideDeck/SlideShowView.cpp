#include "SlideShowView.h"

#include <iostream>

#include "Deck.h"
#include "Slide.h"
SlideShowView::SlideShowView(Deck* mPDeck): m_pDeck{mPDeck} {
}

void SlideShowView::Display() {
	for(size_t i = 0 ; i < m_pDeck->Size() ;++i) {
		std::cout << "\n----------------- SLIDE NO: " << i+1 << " -----------------\n" ;
		std::cout << m_pDeck->GetAt(i)->GetTitle() << '\n' ;
		std::cout << m_pDeck->GetAt(i)->GetDescription() << '\n' ;
		std::cout << "\n----------------------------------------------------\n\n\n" ;
	}
}
