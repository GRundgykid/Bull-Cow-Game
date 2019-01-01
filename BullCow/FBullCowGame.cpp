#include "FBullCowGame.h"
#include <iostream>
#include <map>
#define TMAP std::map

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MyCurrentTries = 1;
	MyMaxTries = MAX_TRIES;
	const std::string HiddenWord = "mouse";
	MyHiddenWord = HiddenWord;
	IsGame1 = false;
	return;
}

//constructor
FBullCowGame::FBullCowGame()
{

	 Reset();
}

int FBullCowGame::NumOfTries() const
{
	return MyMaxTries;
}

bool FBullCowGame::PlayAgain() const
{
	return false;
}

int FBullCowGame::LengthOfWord() const
{
	return 0;
}

bool FBullCowGame::IsGameWon() const
{
	
	return IsGame1;
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTries;
}
//getter
int FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

//check if valid guess
EGuessStatus FBullCowGame::GetGuessValidity(std::string Guess)
{
	
	if (!IsIsogram(Guess))// if the guess isnt an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
	
		return EGuessStatus::Wrong_Length;
	}
	else if (!IsLower(Guess))
	{

		return EGuessStatus::Not_Lowercase;
	}
	else {
		return EGuessStatus::OK;
	}

}
// receives a valid guess and increments turn and returns a count
BullCowCount FBullCowGame::SubmitValidGuess(std::string Guess, std::string HiddenWord)
{
	
	//setup a return variable
	BullCowCount Count;
	int HiddenWordLength = HiddenWord.length();
	// loop through each letter in the guess
	for (int i = 0; i < HiddenWordLength; i++)
	{
		//compare letter against the hidden word
		for (int j = 0; j < HiddenWordLength; j++)
		{

			//if its a match
			if (Guess[i] == HiddenWord[j])
			{
				if (i == j) //if its a match and it in the same place increment bulls
					Count.Bulls++;
				else 				// else increment cows
					Count.Cows++;

			}
			

		}

	}

	if (Guess == MyHiddenWord) 
	{
		IsGame1 = true;
	}

	return Count;
}

bool FBullCowGame::IsIsogram(std::string Guess)
{
	if (Guess.length() < 2) {
		return true;
	}

	TMAP <char, bool> LetterSeen; //setup our map
	for (char Letter : Guess) { //for all letters of the word
		Letter = tolower(Letter);
		//loop through all of the letters  of the word
		if (LetterSeen[Letter]) {
			return false;
			//if the letter is in the map we do NOT have an isogram
		}
		else {
			LetterSeen[Letter] = true;
			//otherwise add the letter to the map as seen
		//return SubmitValidGuess(Guess, Guess).Cows == 0;
		}

	}
	return true;
}

bool FBullCowGame::IsLower(std::string Guess)
{
	for ( auto Letter : Guess) {
		if (!islower(Letter)) {
			return false;
		}
	}

	return true;
}
