#include "stdafx.h"
#include "FBullAndCaws.h"

void FBullAndCaws::Recet()
{
	maxTries=5;
	CurrentTrie=0;
	palabraLoca="loc";
	yourAreWinner = false;
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
	return yourAreWinner;
}

int32 FBullAndCaws::cantidadCaracteres() const
{
	return palabraLoca.length();
}

EGuessStatus FBullAndCaws::CheckGuessValidate(FString palabra)
{
	if (!isIsogram(palabra))
	{
		return EGuessStatus::error_isogram;
	}
	else if (palabra.length() != cantidadCaracteres())
	{
		return EGuessStatus::error_lenght;
	}
	else if (!isLowerCase(palabra))
	{
		return EGuessStatus::error_lowercase;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

BullCawCount FBullAndCaws::submitGuess(FString Guess)
{
	BullCawCount BCCount;
	int32 hiddenword = palabraLoca.length();
	int32 guessChars = Guess.length();


	for (int32 i=0; i < hiddenword; i++)
	{
		for (int32 j = 0; j < guessChars; j++)
		{
			if (Guess[i] == palabraLoca[j])
			{
				if (i == j)
				{
					BCCount.bull++;
				}
				else
				{
					BCCount.caw++;
				}
			}
		}
	}

	if (Guess == palabraLoca)
	{
		yourAreWinner = true;
	}
	
	return BCCount;
}

bool FBullAndCaws::isIsogram(FString palabra) const
{
	if (palabra.length() <= 1) { return true; }

	TMap<char, bool> letterSeen;
	for (auto letter : palabra)
	{
		letter = tolower(letter);
		if (letterSeen[letter])
		{
			return false;
		}
		else
		{
			letterSeen[letter] = true;
		}
	}

	return true;
}

bool FBullAndCaws::isLowerCase(FString palabra) const
{

	for (auto letter : palabra)
	{
		if (!islower(letter))
		{
			return false;
		}
	}

	return true;
}
