#pragma once
#include <string>
#include <vector>

#include "Checkpoint.h"

class Hangman
{
	std::string m_Word{} ;
	std::vector<char> m_PlayerWord{} ;
	std::string m_PlayerInput{} ;
	size_t m_Attempts{} ;
	size_t m_MaxAttempts{6} ;
public:
	void SetWord(const std::string &word) ;
	void SetMaxAttempts(size_t max_attempts) ;
	bool AddChar(char ch) ;
	
	//const std::string & GetWord()const ;
	const std::string & GetPlayerInput()const ;
	const std::vector<char> & GetPlayerWord()const ;
	
	bool IsCompleted()const ;
	bool AttemptsAvailable()const ;
	size_t GetAttempts()const ;
	
	Checkpoint CreateCheckpoint()const ;
	void LoadCheckpoint(Checkpoint checkpoint) ;
};

