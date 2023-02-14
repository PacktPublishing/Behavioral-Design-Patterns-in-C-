#include "Deck.h"
#include "Slide.h"
#include "View.h"
void Deck::AddSlide(SlidePtr slide) {
	m_Slides.push_back(slide) ;
	Notify(m_Slides.size()-1) ;
}

void Deck::ModifyTitle(size_t index, std::string title) {
	m_Slides[index]->SetTitle(title) ;
	Notify(index) ;
}

void Deck::ModifyDescription(size_t index, std::string description) {
	m_Slides[index]->SetDescription(description) ;
	Notify(index) ;
}

size_t Deck::Size() const {
	return m_Slides.size() ;
}

const SlidePtr& Deck::GetAt(size_t index) const {
	return m_Slides[index] ;
}
void Deck::Attach(View* pView) {
	m_Views.push_back(pView) ;
}

void Deck::Detach(View* pView) {
	m_Views.remove(pView) ;
}
void Deck::Notify(size_t index) {
	for(auto view : m_Views) {
		view->Display(index) ;
	}
}
void Deck::Load() {
	Notify(std::numeric_limits<size_t>::max()) ;
}

