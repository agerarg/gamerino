#pragma once
#include <string>
#include <map>
#define TMap std::map
using int32 = int;
using FString = std::string;

struct BullCawCount
{	
	int bull = 0;
	int caw = 0;
};

enum class EGuessStatus {
	NULO,
	OK,
	error_lenght,
	error_isogram,
	error_lowercase
};

class FBullAndCaws {

public:
	void Recet();
	int32 getMaxTries() const;
	int32 getCurrentTry() const;
	bool IsGameWon() const;
	int32 cantidadCaracteres() const;
	EGuessStatus CheckGuessValidate(FString);

	BullCawCount submitGuess(FString);
private:
	int32 maxTries;
	int32 CurrentTrie;
	FString palabraLoca;
	bool yourAreWinner;

	bool isIsogram(FString) const;
	bool isLowerCase(FString) const;

};