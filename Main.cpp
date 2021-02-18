#include <iostream>
#include <string>
#include "FBullCowGameHeader.h"

void printIntro();
void playGame();
std::string getGuess();
bool askToPlayAgain();

FBullCowGame BCGame;

using FText = std::string;
using int32 = int;
			
//	the entry point of our application
int main() {

	bool bPlayAgain = false;

	do {

		printIntro();

		playGame();

		bPlayAgain = askToPlayAgain();

	} while (bPlayAgain);
	return 0;

}



void printIntro() {
	// introduce the game

	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "Can you guess the " << BCGame.getHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n " << std::endl;

}

void playGame()
{
 
	int32 MaxTries = BCGame.getMaxTries();
	//std::cout << MaxTries << std::endl;

	//loop for the number of turns asking for guesses
	constexpr int32 NUMBER_OF_TURNS = 5;
	for (int32 count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		FText Guess = getGuess();

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls: " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows: " << BullCowCount.Cows << std::endl;
		// repeat the guess back to them
		std::cout << std::endl;
	}
}


FText getGuess() {

	int32 CurrentTry = BCGame.getCurrentTry();
	// get a guess from the player
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool askToPlayAgain() 
{
	std::cout << "Do you want to play again ? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return(Response[0] == 'y') || (Response[0] == 'Y');
}
