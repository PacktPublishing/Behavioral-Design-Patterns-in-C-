#include <iostream>

#include "Hangman.h"
#include "CheckpointManager.h"

void Input(Hangman &hangman, char ch) {
	if(hangman.IsCompleted()) {
		return ;
	}
	if(!hangman.AttemptsAvailable()) {
		return ;
	}
	hangman.AddChar(ch) ;
	std::cout << "Your input:" << hangman.GetPlayerInput() << '\n' ;
	std::cout << "Completed word:" ;
	for(auto ch : hangman.GetPlayerWord()) {
		std::cout << ch << ' ' ;
	}
	std::cout << "\n\n" ;
	if(hangman.IsCompleted()) {
		std::cout << "\n===== You won! =====\n" ;
	}
	if(!hangman.AttemptsAvailable()) {
		std::cout << "\n===== You lost! =====\n" ;
	}
}
int main() {
	Hangman hangman ;
	CheckpointManager checkpointManager{} ;
	hangman.SetWord("pepper") ;
	hangman.SetMaxAttempts(6) ;

	Input(hangman, 'q') ;
	Input(hangman, 's') ;
	Input(hangman, 'r') ;
	Input(hangman, 't') ;

	checkpointManager.Serialize(hangman.CreateCheckpoint(), "save01") ;
	
	Input(hangman,'i') ;
	Input(hangman,'o') ;
	Input(hangman,'n') ;

	std::cout << "\n ----- Loading checkpoint...\n" ;
	hangman.SetCheckpoint(checkpointManager.Deserialize("save01")) ;

	Input(hangman, 'p') ;
	Input(hangman, 'e') ;
}
