#pragma once
class Deck;

class EditorView
{
	Deck *m_pDeck{} ;

public:
	EditorView(Deck* mPDeck);
	void Display() ;
};

