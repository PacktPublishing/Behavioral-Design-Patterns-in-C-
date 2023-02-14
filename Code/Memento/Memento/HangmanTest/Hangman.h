#pragma once
#include <string>
#include <vector>

class Hangman
{

public:
	struct GameState{
		std::string m_Word{} ;
		std::vector<char> m_PlayerWord{} ;
		std::string m_PlayerInput{} ;
		size_t m_Attempts{} ;
		size_t m_MaxAttempts{} ;
	} ;
	void SetWord(std::string word) ;
	void SetMaxAttempts(size_t maxAttempts) ;
	void AddChar(char ch) ;

	const std::string & GetPlayerInput()const ;
	const std::vector<char> & GetPlayerWord()const ;

	bool IsCompleted()const ;
	bool AttemptsAvailable()const ;

	GameState CreateCheckpoint()const ;
	void SetCheckpoint(GameState checkpoint) ;
private:
	GameState m_State{} ;
};

