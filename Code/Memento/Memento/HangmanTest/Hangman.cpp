#include "Hangman.h"

void Hangman::SetWord(std::string word) {
	m_State.m_Word = std::move(word) ;
	m_State.m_PlayerWord.resize( m_State.m_Word.size()) ;
	m_State.m_PlayerInput.resize(m_State.m_Word.size()) ;
	/*
	 * tweet
	 * -----
	 * t---t
	 * t-eet
	 * r
	 * +++++
	 * r++++
	 */

	std::fill(begin(m_State.m_PlayerWord), end( m_State.m_PlayerWord), '-') ;
	std::fill(begin(m_State.m_PlayerInput), end(m_State.m_PlayerInput), '+') ;
}

void Hangman::SetMaxAttempts(size_t maxAttempts) {
	m_State.m_MaxAttempts = maxAttempts ;
}

void Hangman::AddChar(char ch) {
	size_t index{} ;
	bool added{false} ;
	while((index = m_State.m_Word.find(ch, index)) != std::string::npos) {
		m_State.m_PlayerWord[index] = ch ;
		++index ;
		added = true ;
	}
	if(!added) {
		m_State.m_PlayerInput[m_State.m_Attempts++] = ch ;
	}
}

const std::string& Hangman::GetPlayerInput() const {
	return m_State.m_PlayerInput ;
}

const std::vector<char>& Hangman::GetPlayerWord() const {
	return m_State.m_PlayerWord ;
}

bool Hangman::IsCompleted() const {
	std::string tempWord{begin(m_State.m_PlayerWord), end(m_State.m_PlayerWord)} ;
	return tempWord == m_State.m_Word ;
}

bool Hangman::AttemptsAvailable() const {
	return m_State.m_Attempts < m_State.m_MaxAttempts ;
}
Hangman::GameState Hangman::CreateCheckpoint()const {
	return m_State ;
}
void Hangman::SetCheckpoint(Hangman::GameState checkpoint) {
	m_State.m_PlayerWord = checkpoint.m_PlayerWord ;
	m_State.m_PlayerInput = checkpoint.m_PlayerInput ;
	m_State.m_Word = checkpoint.m_Word ;
	m_State.m_Attempts = checkpoint.m_Attempts ;
	m_State.m_MaxAttempts = checkpoint.m_MaxAttempts ;
}

