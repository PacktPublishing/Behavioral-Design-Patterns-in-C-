#pragma once
#include <memory>
#include <string>
#include <vector>
class Slide ;
using SlidePtr = std::shared_ptr<Slide> ;
class Deck
{
	std::vector<SlidePtr> m_Slides{} ;
public:
	void AddSlide(SlidePtr slide) ;
	void ModifyTitle(size_t index, std::string title) ;
	void ModifyDescription(size_t index, std::string description) ;
	size_t Size()const ;
	const SlidePtr & GetAt(size_t index) const ;
};

