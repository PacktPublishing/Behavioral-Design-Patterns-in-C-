#include "TextDocument.h"

#include <iostream>
#include <string>

void TextDocument::Read(std::ifstream & in) {
	std::getline(in, m_Text) ;
}
void TextDocument::Write(std::ofstream & out) {
	out.seekp(0) ;
	out << m_Text ;
}

void TextDocument::SetText(std::string text) {
	m_Text = std::move(text) ;
	SetModified(true) ;
}
void TextDocument::Print() {
	std::cout << "Text:" << m_Text << std::endl ;
}



