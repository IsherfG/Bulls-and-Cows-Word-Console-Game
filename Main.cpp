#include <iostream>
#include <string>

using namespace std;

void printIntro();
void playGame();
string getGuess();
bool askToPlayAgain();

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
	constexpr int WORLD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows" << endl;
	cout << "Can you guess the " << WORLD_LENGTH;
	cout << " letter isogram I'm thinking of?\n " << endl;

}

void playGame()
{
	//loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		string Guess = getGuess();

		// repeat the guess back to them
		cout << "Your guess was: " << Guess << endl;
		cout << endl;
	}
}


string getGuess() {

	// get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

bool askToPlayAgain() 
{
	cout << "Do you want to play again ? ";
	string Response = "";
	getline(cin, Response);
	return(Response[0] == 'y') || (Response[0] == 'Y');
}
