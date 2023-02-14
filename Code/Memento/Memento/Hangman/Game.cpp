#include "Game.h"


#include <ctime>
#include <iostream>

char Game::ReadChar() {
	char ch{};
	std::cout << "Enter char:";
	std::cin >> ch;
	return ch;
}



bool Game::CheckStatus() {
	if (!m_Hangman.AttemptsAvailable()) {
		std::cout << "No more attempts. You lose!\n";
		auto index = GetCheckpointIndex();
		if (index == 0) {
			return false ;
		}
		auto cp = m_CheckpointManager.Restore(index);
		m_Hangman.LoadCheckpoint(cp);
		system("cls") ;
		std::cout << "=== Checkpoint restored === \n";
		PrintInfo() ;
	}
	return true ;
}

void Game::PrintInfo() {
	Print(m_Hangman.GetPlayerWord(), "Completed word:") ;
	Print(m_Hangman.GetPlayerInput(), "Your input:", " ") ;
}

size_t Game::GetCheckpointIndex() {
	size_t index{};
	std::cout << "Steps to retrace (0 to quit)?";
	std::cin >> index;
	return index;
}



Game::Game() {
	std::vector<std::pair<std::string, std::string>> words{
		{"pepper", "A spice"},
		{"truck", "Vehicle for transporting goods"},
		{"shadow", "Visible only during the day & follows you"},
		{"jupiter", "largest planet"},
		{"giraffe", "tallest animal"},
		{"kashmir", "Place in north India. Also known as heaven on earth"},
	} ;
	srand(time(nullptr)) ;
	auto p = words[rand() % words.size()] ;
	m_Hangman.SetMaxAttempts(p.first.size()) ;
	m_Hangman.SetWord(p.first) ;
	std::cout << "Hint:" << p.second << '\n' ;
	Print(m_Hangman.GetPlayerWord(), "Word:") ;
}

void Game::Run() {
	while (true) {
		m_CheckpointManager.Save(m_Hangman.CreateCheckpoint());
		m_Hangman.AddChar(ReadChar());
		Print(m_Hangman.GetPlayerWord(), "Completed word:") ;
		Print(m_Hangman.GetPlayerInput(), "Your input:", " ") ;
		if (m_Hangman.IsCompleted()) {
			std::cout << "You won!\n";
			break ;
		}
		if(!CheckStatus()) {
			break ;
		}
		system("Pause");
		system("cls");
	}
}
