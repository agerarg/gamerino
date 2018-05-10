#pragma once
#include <string>
class FBullAndCaws {

public:
	void Recet();
	int getMaxTries() const;
	int getCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidate(std::string palabra);

private:
	int maxTries = 5;
	int CurrentTrie = 0;

};