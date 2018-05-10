// CowsAndBulls.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include "FBullAndCaws.h"
void introduccion();
std::string getGuess();
void playGame();
bool askPlayAgain();
FBullAndCaws BCgame;
int main()
{
	int maxTries = BCgame.getMaxTries();
	std::cout << "num: " << maxTries;
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
std::string getGuess()
{
	int currTrie = BCgame.getCurrentTry();
	std::cout << "Intento (" << currTrie << ") ponga su numero" << "\n";
	// get the guess of the user
	std::string Guess = "";
	getline(std::cin, Guess);
	return Guess;
}

void playGame() {
	int maxTries = BCgame.getMaxTries();

	for (int count = 1; count <= maxTries; count++)
	{
		std::cout << "ingreso: " << getGuess() << "\n";
		std::cout << std::endl;
	}

}

bool askPlayAgain()
{
	std::cout << "queres jugar de nuevo?" << std::endl;
	std::string responcer = "";
	getline(std::cin, responcer);
	if (responcer[0] == 'y' || responcer[0] == 'Y')
		return true;
	else
		return false;
}
