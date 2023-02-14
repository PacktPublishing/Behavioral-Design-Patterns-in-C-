#pragma once
#include <list>
#include <memory>
#include <string>
#include <vector>
class View;
class Slide ;
using SlidePtr = std::shared_ptr<Slide> ;
class Deck
{
	std::vector<SlidePtr> m_Slides{} ;
	std::list<View*> m_Views{} ;
public:
	void Attach(View *pView) ;
	void Detach(View *pView) ;
	void Notify(size_t index) ;
	void AddSlide(SlidePtr slide) ;
	void ModifyTitle(size_t index, std::string title) ;
	void ModifyDescription(size_t index, std::string description) ;
	size_t Size()const ;
	const SlidePtr & GetAt(size_t index) const ;
	void Load() ;
};

