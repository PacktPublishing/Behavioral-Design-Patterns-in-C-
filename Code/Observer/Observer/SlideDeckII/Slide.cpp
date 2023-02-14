#include "Slide.h"



void Slide::SetTitle(std::string title) {
	m_Title = title ;
}

void Slide::SetDescription(std::string description) {
	m_Description = description ;
}

const std::string& Slide::GetTitle() const {
	return m_Title ;
}

const std::string& Slide::GetDescription() const {
	return m_Description ;
}

Slide::Slide(std::string mTitle, std::string mDescription): m_Title{std::move(mTitle)},
                                                            m_Description{std::move(mDescription)} {
}
