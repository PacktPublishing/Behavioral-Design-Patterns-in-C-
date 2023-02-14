#include "Application.h"

#include "Console.h"

void Application::AddText(const std::string& text) {
	m_Text += text + '\n'; 
}

void Application::RemoveText(size_t index, size_t count) {
	m_Text.erase(index,count) ;
}

void Application::Overwrite(size_t index, const std::string& text) {
	std::copy(text.begin(), text.end(), m_Text.begin() + index) ;
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