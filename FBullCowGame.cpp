#include "FBullCowGameHeader.h"

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	myMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "donkey";
	MyHiddenWord = HIDDEN_WORD;
	myCurrentTry = 1;
	return;
}
 
int32 FBullCowGame::getMaxTries() const {return myMaxTries;}

int32 FBullCowGame::getCurrentTry() const {return myCurrentTry;}

int32 FBullCowGame::getHiddenWordLength() const{return MyHiddenWord.length();}


bool FBullCowGame::isGameWon() const {

	return false;
}

EWordStatus FBullCowGame::checkGuessValidity(FString) const {

	return EWordStatus::OK;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	myCurrentTry++;

	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		for (int32 GChar = 0; GChar<HiddenWordLength; GChar++)
		{
			if (Guess[MHWChar] == MyHiddenWord[GChar]) 
			{
				if(MHWChar == GChar)
				{
					BullCowCount.Bulls++;
				}
				else 
				{
					BullCowCount.Cows++;
				}
			}
		}
	}
		return BullCowCount;
}
