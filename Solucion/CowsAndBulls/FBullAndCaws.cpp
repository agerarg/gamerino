#include "stdafx.h"
#include "FBullAndCaws.h"

void FBullAndCaws::Recet()
{
	maxTries=5;
	CurrentTrie=0;
	palabraLoca="locura";
	return;
}

int FBullAndCaws::getMaxTries() const
{
	return maxTries;
}

int FBullAndCaws::getCurrentTry() const
{
	return CurrentTrie;
}

bool FBullAndCaws::IsGameWon() const
{
	return false;
}

bool FBullAndCaws::CheckGuessValidate(FString palabra)
{
	return false;
}

BullCawCount FBullAndCaws::submitGuess(FString Guess)
{
	BullCawCount BCCount;

	for (int32 i=0; i < palabraLoca.length(); i++)
	{
		if (Guess[i] == palabraLoca[i])
			BCCount.caw++;
		else
			BCCount.bull;
	}
	


	return BCCount;
}
