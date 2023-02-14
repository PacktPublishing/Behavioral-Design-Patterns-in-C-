#include "CheckpointManager.h"
#include <fstream>
#include <iostream>

void CheckpointManager::Serialize(Hangman::GameState checkpoint, std::string_view fileName) {
	std::ofstream out{fileName.data()} ;
	out << checkpoint.m_Word << '\n' ;
	out << checkpoint.m_Attempts << '\n' ;
	out << checkpoint.m_MaxAttempts << '\n' ;
	out << checkpoint.m_PlayerInput << '\n' ;
	for(auto ch : checkpoint.m_PlayerWord) {
		out << ch ;
	}
}

Hangman::GameState CheckpointManager::Deserialize(std::string fileName) {
	std::ifstream input{fileName.data()} ;
	if(!input) {
		throw std::runtime_error{"Could not open the file\n"} ;
	}
	Hangman::GameState checkpoint{} ;
	input >> checkpoint.m_Word ;
	input >> checkpoint.m_Attempts ;
	input >> checkpoint.m_MaxAttempts ;
	input >> checkpoint.m_PlayerInput ;

	input.ignore(1) ;
	char ch ;
	while(input.get(ch)) {
		checkpoint.m_PlayerWord.push_back(ch) ;
	}
	return checkpoint ;
}
