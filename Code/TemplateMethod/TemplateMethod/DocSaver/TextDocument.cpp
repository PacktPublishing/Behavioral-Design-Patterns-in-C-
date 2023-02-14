#include "TextDocument.h"

#include <iostream>
#include <string>


void TextDocument::Load() {
	if(m_IsModified) {
		std::cout << "Save current changes first\n" ;
		return ;
	}
	std::cout << "File name?";
	std::string fileName{};
	std::getline(std::cin, fileName);
	m_Stream.open(fileName, m_Stream.in);
	std::getline(m_Stream, m_Text);
	m_Stream.close() ;
}

void TextDocument::Save() {
	if (!m_Stream.is_open()) {
		std::cout << "File name?";
		std::string fileName{};
		std::getline(std::cin, fileName);
		m_Stream.open(fileName, m_Stream.out);
	}
	m_Stream.seekp(0) ;
	m_Stream << m_Text;
}

void TextDocument::SetText(std::string text) {
	m_Text = std::move(text) ;
	m_IsModified = true ;
}

void TextDocument::Print() {
	std::cout << "Text:" << m_Text << std::endl ;
}
