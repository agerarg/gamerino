#pragma once
#include <string>
using int32 = int;
using FString = std::string;

struct BullCawCount
{	
	int bull = 0;
	int caw = 0;
};

class FBullAndCaws {

public:
	void Recet();
	int32 getMaxTries() const;
	int32 getCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidate(FString palabra);

	BullCawCount submitGuess(FString Guess);
private:
	int32 maxTries;
	int32 CurrentTrie;
	FString palabraLoca;
};