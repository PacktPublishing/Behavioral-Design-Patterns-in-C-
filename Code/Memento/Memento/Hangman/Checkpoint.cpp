#include "Checkpoint.h"

const std::vector<char>& Checkpoint::GetPlayerWord() const {
	return m_PlayerWord ;
}

const std::string& Checkpoint::GetPlayerInput() const {
	return m_Input ;
}

size_t Checkpoint::GetAttempts() const {
	return m_Attempts ;
}
