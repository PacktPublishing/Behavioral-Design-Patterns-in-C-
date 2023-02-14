#pragma once
#include <vector>
#include <string_view>
#include "Hangman.h"

class CheckpointManager
{
	std::vector<Hangman::GameState> m_Checkpoints{} ;
public:
	void Serialize(Hangman::GameState checkpoint, std::string_view fileName) ;
	Hangman::GameState Deserialize(std::string fileName) ;
};

