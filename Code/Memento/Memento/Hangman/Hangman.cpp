#include "Hangman.h"

void Hangman::SetWord(const std::string& word) {
	m_Word = word;
	m_PlayerWord.resize(m_Word.size());
	m_PlayerInput.resize(m_Word.size());
	std::fill(begin(m_PlayerWord), end(m_PlayerWord), '-');
	std::fill(begin(m_PlayerInput), end(m_PlayerInput), '+');
}

void Hangman::SetMaxAttempts(size_t max_attempts) {
	m_MaxAttempts = max_attempts;
}

bool Hangman::AddChar(char ch) {
	if (m_Attempts > m_MaxAttempts) {
		return false;
	}
	bool added{ false };
	size_t index{  };
	while ((index = m_Word.find(ch, index)) != std::string::npos) {
		m_PlayerWord[index] = ch;
		index += 1;
		added = true;
	}
	if (!added) {
		m_PlayerInput[m_Attempts++] = ch;
	}
	return added;
}

//const std::string& Hangman::GetWord() const {
//	return m_Word;
//}

const std::string& Hangman::GetPlayerInput() const {
	return m_PlayerInput;
}

bool Hangman::IsCompleted() const {
	std::string tempWord{ begin(m_PlayerWord), end(m_PlayerWord) };
	return tempWord == m_Word;
}

size_t Hangman::GetAttempts() const {
	return m_Attempts;
}

bool Hangman::AttemptsAvailable() const {
	return m_Attempts < m_MaxAttempts;
}

Checkpoint Hangman::CreateCheckpoint() const {
	return { m_PlayerWord, m_PlayerInput, m_Attempts };
}

void Hangman::LoadCheckpoint(Checkpoint checkpoint) {
	m_Attempts = checkpoint.GetAttempts();
	m_PlayerInput = checkpoint.GetPlayerInput();
	m_PlayerWord = checkpoint.GetPlayerWord();
}

const std::vector<char>& Hangman::GetPlayerWord() const {
	return m_PlayerWord;
}
