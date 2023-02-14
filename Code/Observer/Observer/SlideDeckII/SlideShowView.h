#pragma once
#include "View.h"
class Deck;

class SlideShowView : public View
{
	Deck *m_pDeck{} ;

public:
	SlideShowView(Deck* mPDeck);
	void ShowSlide(size_t i);
	void Display(size_t index) override;
};

