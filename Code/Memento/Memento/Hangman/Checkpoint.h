#pragma once
#include <string>
#include <vector>

struct Checkpoint
{
	std::vector<char> m_PlayerWord{} ;
	std::string m_Input{} ;
	size_t m_Attempts{} ;

public:
	Checkpoint()=default ;
	Checkpoint(const std::vector<char>& mPlayerWord, const std::string& mInput, size_t mAttempts)
		: m_PlayerWord{mPlayerWord},
		  m_Input{mInput},
		  m_Attempts{mAttempts} {
	}
	const std::vector<char> & GetPlayerWord()const ;
	const std::string & GetPlayerInput()const ;
	size_t GetAttempts()const ;
};

