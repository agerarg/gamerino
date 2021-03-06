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
	EGuessStatus Estado = EGuessStatus::NULO;
	FString Guess = "";
	do {
		getline(std::cin, Guess);
		Estado = BCgame.CheckGuessValidate(Guess);

		switch (Estado)
		{
		case EGuessStatus::error_lenght:
			std::cout << "cantidad de letras incorrecta por favor ponga " << BCgame.cantidadCaracteres() << " caracteres \n\n";
		break;
		case EGuessStatus::error_isogram:
			std::cout << "La palabra no es un isogram \n\n";
		break;
		case EGuessStatus::error_lowercase:
			std::cout << "La palabra tiene mayusculas \n\n";
		break;
		default:
			return Guess;
		break;
		}
	} while (Estado != EGuessStatus::OK);
}

void playGame() {
	BCgame.Recet();
	int32 maxTries = BCgame.getMaxTries();
	int32 cantCarac = BCgame.cantidadCaracteres();
	int32 currTrie = 0;
	std::cout << "La palabra tiene " << cantCarac << " caracteres" << std::endl;

	while(!BCgame.IsGameWon() && currTrie < maxTries)
	{
		std::cout << "Intento (" << currTrie << ") ponga su palabra" << "\n";
		BullCawCount Contadoreitor = BCgame.submitGuess(getGuess());
		currTrie++;
		std::cout << " BULLS= " << Contadoreitor.bull;
		std::cout << " CAWS= " << Contadoreitor.caw;

		std::cout << std::endl;
	}
	if(currTrie >= maxTries)
		std::cout << "YOU FAIL" << std::endl;
	else
		std::cout << "YOU ARE WINNER" << std::endl;

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
