#include "Application.h"

#include <iostream>


#include "Console.h"
#include "Menu.h"

void Application::AddText(const std::string& text) {
	m_Text += text + '\n'; 
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
void Application::Execute(int id) {
		switch(id) {
	case 0:
		Display() ;
		break ;
	case 1:
		InputAdd() ;
		break ;
	case 2:
		InputInsert() ;
		break ;
	case 3:
		InputOverwrite() ;
		break ;
	case 4:
		InputRemove() ;
		break ;
	case 5:
		InputSetColor() ;
		break ;
	case 6:
		InputSetBold() ;
		break ;
	}
}
void Application::InputAdd() {
	std::string text ;
	std::cout << "Enter text to add:" ;
	std::cin.ignore() ;
	std::getline(std::cin, text) ;
	AddText(text) ;
	Message("Text added successfully!") ;
}
void Application::InputInsert() {
	std::string text ;
	std::cout << "Enter text:" ;
	std::cin.ignore() ;
	std::getline(std::cin, text) ;
	std::cout << "Position of insertion:" ;
	size_t index{} ;
	std::cin >> index ;
	InsertText(index, text) ;
	Message("Text inserted!") ;
}

void Application::InputOverwrite() {
	std::string text ;
	std::cout << "Enter text:" ;
	std::cin.ignore() ;
	std::getline(std::cin, text) ;
	std::cout << "Position of overwrite:" ;
	size_t index{} ;
	std::cin >> index ;
	Overwrite(index, text) ;
	Message("Text overwritten!") ;
}
void Application::InputRemove() {
	size_t start, count ;
	std::cout << "Starting index?" ;
	std::cin >> start ;
	std::cout << "How many characters to remove?" ;
	std::cin >> count;
	RemoveText(start, count ) ;
	Message("Text removed!") ;
}
void Application::InputSetBold() {
	bool bold{} ;
	std::cout <<"Press (b) for bold or any other key for normal text:" ;
	char ch ;
	std::cin >> ch ;
	SetBold(ch == 'b'? true :false);
	Message("Text property changed!") ;
}
void Application::InputSetColor() {
	char chColor{} ;
	Color color{} ;
	std::cout << "Choose color (r, g, b, w)?" ;
	std::cin >> chColor ;
	switch(chColor) {
	case 'r':
		color = Color::RED ;
		break ;
	case 'g':
		color = Color::GREEN ;
		break ;
	case 'b' :
		color = Color::BLUE ;
		break ;
	case 'w':
		color = Color::WHITE ;
		break ;
	default:
		Message("Unknown color") ;
		return ; 
	}
	SetColor(color) ;
	Message("Color set!") ;
}