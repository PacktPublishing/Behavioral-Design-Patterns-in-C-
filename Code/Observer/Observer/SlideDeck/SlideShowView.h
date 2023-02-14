#pragma once
class Deck;

class SlideShowView
{
	Deck *m_pDeck{} ;

public:
	SlideShowView(Deck* mPDeck);
	void Display() ;
};

