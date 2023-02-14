#include "EditorView.h"

#include <iostream>

#include "Deck.h"
#include "Slide.h"
EditorView::EditorView(Deck* mPDeck): m_pDeck{mPDeck} {
}

void EditorView::ShowSlide(size_t i) {
	std::cout << "\nTitle:" << m_pDeck->GetAt(i)->GetTitle() << '\n' ;
	std::cout << "Description:" << m_pDeck->GetAt(i)->GetDescription() << '\n' ;
}

void EditorView::Display(size_t index) {
	if(index != std::numeric_limits<size_t>::max()) {
		ShowSlide(index) ;
		return ;
	}
	for(size_t i = 0 ; i < m_pDeck->Size() ;++i) {
		ShowSlide(i);
	}
}
