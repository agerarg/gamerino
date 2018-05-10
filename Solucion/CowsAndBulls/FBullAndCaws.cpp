#include "stdafx.h"
#include "FBullAndCaws.h"

void FBullAndCaws::Recet()
{
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

bool FBullAndCaws::CheckGuessValidate(std::string palabra)
{
	return false;
}
