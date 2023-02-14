#include "Application.h"

#include <iostream>
#include "Console.h"

void Application::AddText(const std::string& text) {
	m_Text += text + ' '; 
}

void Application::RemoveText(size_t index, size_t count) {
	m_Text.erase(index,count) ;
}

void Application::Overwrite(size_t index, const std::string& text) {
	for(size_t i = 0 ; i < text.size() ; ++i) {
		m_Text[i] = text[i] ;
	}
}

void Application::SetColor(Color color) {
	m_Color = color ;
}

void Application::SetBold(bool bold) {
	m_Bold = bold ;
}

void Application::InsertText(size_t index, const std::string& text) {
	m_Text.insert(index, text) ;
}

size_t Application::TextSize() const {
	return m_Text.size() ;
}

void Application::Display() {
	Console::WriteLine(m_Text, m_Color, m_Bold) ;
}
bool Application::IsBold() const {
	return m_Bold ;
}
Color Application::GetColor() const {
	return m_Color ;
}

const std::string& Application::GetText() const {
	return m_Text ;
}

