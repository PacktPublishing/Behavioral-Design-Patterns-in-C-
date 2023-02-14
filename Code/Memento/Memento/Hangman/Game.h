#pragma once
#include "CheckpointManager.h"
#include "Hangman.h"
#include <iostream>
class Game
{
	Hangman m_Hangman{} ;
	CheckpointManager m_CheckpointManager{} ;
	char ReadChar() ;
	void InputLoop() ;
	bool CheckStatus() ;
	void PrintInfo() ;
	size_t GetCheckpointIndex() ;
	template<typename Container>
	void Print(const Container& data, const std::string& message, const std::string& separator = "") {
		std::cout << message;
		for (auto ch : data) {
			std::cout << ch << separator;
		}
		std::cout << '\n';
	}
public:
	Game() ;
	void Run() ;
};

