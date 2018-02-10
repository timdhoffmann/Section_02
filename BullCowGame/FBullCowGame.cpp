#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessIsValid(FString Guess) const
{
	// if the guess isn't an isogram, return error
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	// if the guess isn't all lowercase, return error
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	// if the guess length is wrong, return error
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	// Otherwise return ok
	else
	{
		return EGuessStatus::Ok; //TODO: make actual error.
	}
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;

	return;
}

// Receives a valid guess, increments turn and returns count.
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	// Loop through all letters in the hidden word.

	for (int32 HiddenWordChar = 0; HiddenWordChar < GetHiddenWordLength(); HiddenWordChar++)
	{
		// Compare letters against the guess.
		for (int32 GuessChar = 0; GuessChar < GetHiddenWordLength(); GuessChar++)
		{
			// if they match
			if (Guess[GuessChar] == MyHiddenWord[HiddenWordChar]) 
			{
				// if they're in the same place
				if (HiddenWordChar == GuessChar) 
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

	if (BullCowCount.Bulls == GetHiddenWordLength())
	{
		bGameIsWon = true;
	}

	return BullCowCount;
}
