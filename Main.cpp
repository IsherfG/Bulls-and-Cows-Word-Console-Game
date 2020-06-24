#include <iostream>
#include <string>

using namespace std;

void printIntro();
string getGuessAndPrintBack();

//	the entry point of our application
int main() {

	printIntro();

	getGuessAndPrintBack();

	cout << endl;
	return 0;

}

void printIntro() {
	// introduce the game
	constexpr int WORLD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows" << endl;
	cout << "Can you guess the " << WORLD_LENGTH;
	cout << " letter isogram I'm thinking of?\n " << endl;

}


string getGuessAndPrintBack() {

	// get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	// repeat the guess back to them
	cout << "Your guess was: " << Guess << endl;
	return Guess;
}
