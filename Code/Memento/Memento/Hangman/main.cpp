#include <iostream>


#include "CheckpointManager.h"
#include "Game.h"
#include "Hangman.h"
enum class Status { RUNNING, WON, LOST };
char ReadChar() {
	char ch{};
	std::cout << "Enter char:";
	std::cin >> ch;
	return ch;
}

void PrintGameInfo(const Hangman& eng) {
	std::cout << "Completed word:";
	for (auto ch : eng.GetPlayerWord()) {
		std::cout << ch << ' ';
	}
	std::cout << '\n';
	std::cout << "Your input:" << eng.GetPlayerInput() << std::endl;
}
bool CheckStatus(const Hangman& eng) {
	if (eng.IsCompleted()) {
		std::cout << "You won!\n";
		return true;
	}
	if (!eng.AttemptsAvailable()) {
		std::cout << "No more attempts. You lose!\n";
		return true;
	}
	return false;
}
void InputLoop(Hangman& hangman, CheckpointManager& chkMgr) {
	while (true) {
		chkMgr.Save(hangman.CreateCheckpoint());
		hangman.AddChar(ReadChar());
		PrintGameInfo(hangman);
		if (CheckStatus(hangman)) {
			break;
		}
		system("Pause");
		system("cls");
	}
}
size_t GetCheckpointIndex() {
	size_t index{};
	std::cout << "Checkpoint # (0 to quit)?";
	std::cin >> index;
	return index;
}
void oldmain() {
	CheckpointManager chkMgr{};
	Hangman hangman{};
	hangman.SetMaxAttempts(3);
	hangman.SetWord("pepper");
	while (true) {
		InputLoop(hangman, chkMgr);

		auto index = GetCheckpointIndex();
		if (index == 0)
			break;
		auto cp = chkMgr.Restore(index);
		hangman.LoadCheckpoint(cp);
		std::cout << "== Checkpoint restored ==\n\n";
		PrintGameInfo(hangman);
		system("Pause");
		system("cls");
	}
}


int main() {
	Game game ;
	game.Run() ;
}