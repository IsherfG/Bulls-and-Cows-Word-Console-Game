#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus
{
	OK,
	Not_isogram,
	Wrong_lenght,
	Not_lowercase
};

class FBullCowGame 
{

public:
	FBullCowGame();//Constructor

	void Reset(); // TODO make a more rich return value
	int32 getMaxTries () const;
	int32 getCurrentTry() const;
	int32 getHiddenWordLength() const;
	bool isGameWon() const;
	EWordStatus checkGuessValidity(FString) const; // TODO make a more rich return value
	//counts bulls and cows, and increases try # assuming valid guess
	FBullCowCount SubmitGuess(FString);

private:

	int32 myCurrentTry ;
	int32 myMaxTries ;
	FString MyHiddenWord;

};