#include "EditorView.h"

#include <iostream>

#include "Deck.h"
#include "Slide.h"
EditorView::EditorView(Deck* mPDeck): m_pDeck{mPDeck} {
}

void EditorView::Display() {
	for(size_t i = 0 ; i < m_pDeck->Size() ;++i) {
		std::cout << "\nTitle:" << m_pDeck->GetAt(i)->GetTitle() << '\n' ;
		std::cout << "Description:" << m_pDeck->GetAt(i)->GetDescription() << '\n' ;
	}
}
