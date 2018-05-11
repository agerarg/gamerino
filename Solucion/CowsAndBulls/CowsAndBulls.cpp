// CowsAndBulls.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include "FBullAndCaws.h"
void introduccion();
void playGame();
bool askPlayAgain();
FBullAndCaws BCgame;

using FString = std::string;
using int32 = int;

int main()
{
	do {
		// introduccing the game
		introduccion();
		// get the guess of the user
		playGame();
		// repeat the process
	} while (askPlayAgain());
    return 0;
}

void introduccion()
{
	std::cout << "Bienvenido \n";
	return;
}
FString getGuess()
{
	int32 currTrie = BCgame.getCurrentTry();
	std::cout << "Intento (" << currTrie << ") ponga su numero" << "\n";
	// get the guess of the user
	FString Guess = "";
	getline(std::cin, Guess);
	return Guess;
}

void playGame() {
	BCgame.Recet();
	int32 maxTries = BCgame.getMaxTries();

	for (int32 count = 1; count <= maxTries; count++)
	{
		BullCawCount Contadoreitor = BCgame.submitGuess(getGuess());
		std::cout << "- " << Contadoreitor.bull;
		std::cout << "- " << Contadoreitor.caw;
		std::cout << std::endl;
	}


}

bool askPlayAgain()
{
	std::cout << "queres jugar de nuevo?" << std::endl;
	FString responcer = "";
	getline(std::cin, responcer);
	if (responcer[0] == 'y' || responcer[0] == 'Y')
		return true;
	else
		return false;
}
