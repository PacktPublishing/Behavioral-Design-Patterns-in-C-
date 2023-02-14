#include "Deck.h"
#include "Slide.h"
void Deck::AddSlide(SlidePtr slide) {
	m_Slides.push_back(slide) ;
}

void Deck::ModifyTitle(size_t index, std::string title) {
	m_Slides[index]->SetTitle(title) ;
}

void Deck::ModifyDescription(size_t index, std::string description) {
	m_Slides[index]->SetDescription(description) ;
}

size_t Deck::Size() const {
	return m_Slides.size() ;
}

const SlidePtr& Deck::GetAt(size_t index) const {
	return m_Slides[index] ;
}
