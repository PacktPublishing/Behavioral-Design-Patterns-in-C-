#pragma once
#include "View.h"
class Deck;

class EditorView : public View
{
	Deck *m_pDeck{} ;

public:
	EditorView(Deck* mPDeck);
	void ShowSlide(size_t i);
	void Display(size_t index)override ;
};

