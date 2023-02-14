#include "Menu.h"

#include <iostream>
#include "Application.h"
void Message(const std::string &text) {
	std::cout << "\n------ " << text << " ------" << std::endl;
	system("pause") ;
	system("cls") ;
}
Menu::Menu(Application* app) :m_pApp{app}{
}

void Menu::Init(int choice, void* pCallback) {
	m_InputTable[choice] = pCallback ;
}


void Menu::Run() {
	bool exit{false} ;
	int choice{} ;
	while(!exit) {
		m_pApp->Display() ;
		std::cout << "\n----------------------------------\n" ;
		std::cout << "1. Add\n" ;
		std::cout << "2. Insert\n" ;
		std::cout << "3. Overwrite\n" ;
		std::cout << "4. Erase\n" ;
		std::cout << "5. Change color\n" ;
		std::cout << "6. Toggle Bold\n" ;
		std::cout << "7. Undo\n" ;
		std::cout << "Your choice (0 to exit)?" ;
		std::cin >> choice ;
		std::cout << '\n' ;
		switch (choice) {
		case 0:
			exit = true ;
			break ;
		case 1:
			AddText() ;
			break ;
		case 2:
			InsertText() ;
			break ;
		case 3:
			Overwrite() ;
			break ;
		case 4:
			RemoveText() ;
			break ;
		case 5:
			SetColor() ;
			break ;
		case 6:
			SetBold() ;
			break ;
		default:
			Message("Unknown option.Try again!") ;
			break ;
		}
	}
	Message("Application terminated") ;
}


void Menu::AddText() {
	std::string text ;
	std::cout << "Enter text to add:" ;
	std::cin.ignore() ;
	std::getline(std::cin, text) ;
	m_pApp->AddText(text) ;
	Message("Text added successfully!") ;
}

void Menu::Overwrite() {
	std::string text ;
	std::cout << "Enter text:" ;
	std::cin.ignore() ;
	std::getline(std::cin, text) ;
	std::cout << "Position of overwrite:" ;
	size_t index{} ;
	std::cin >> index ;
	m_pApp->Overwrite(index, text) ;
	Message("Text overrwritten!") ;
}

void Menu::RemoveText() {
	size_t start, count ;
	std::cout << "Starting index?" ;
	std::cin >> start ;
	std::cout << "How many characters to remove?" ;
	std::cin >> count;
	m_pApp->RemoveText(start, count ) ;
	Message("Text removed!") ;
	
}

void Menu::SetColor() {
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
	m_pApp->SetColor(color) ;
	Message("Color set!") ;
}

void Menu::SetBold() {
	bool bold{} ;
	std::cout <<"Press (b) for bold or any other key for normal text:" ;
	char ch ;
	std::cin >> ch ;
	if(ch == 'b') {
		m_pApp->SetBold(true) ;
	}else {
		m_pApp->SetBold(false) ;
	}
	Message("Text property changed!") ;
	
}

void Menu::InsertText() {
	std::string text ;
	std::cout << "Enter text:" ;
	std::cin.ignore() ;
	std::getline(std::cin, text) ;
	std::cout << "Position of insertion:" ;
	size_t index{} ;
	std::cin >> index ;
	m_pApp->InsertText(index, text) ;
	Message("Text inserted!") ;
}

