/* This is the console executable  that makes use of the Bull Cows Game class.

*/
#include <iostream>
#include <string>
#include "FBullCowGame.h"


void PrintIntro();
void PrintGameSummary();
void PlayGame();
std::string GetValidGuess();
void RepeatGuess(std::string &Guess);
bool AskToPlayAgain();
FBullCowGame FBCGame; //instantiate a new game

//start of game


int main()
{
	//std::cout << FBCGame.GetCurrentTry();
	bool bplayAgain = true;
	do
	{
		PrintIntro();
		PlayGame();
		bplayAgain = AskToPlayAgain();
	} while (bplayAgain);
	return 0; //exit game
	
}

void PlayGame()
{
	//loop for asking for guesses

	FBCGame.Reset(); //same as the constructor

	int MyMaxTries = FBCGame.NumOfTries();

	//loop asking for guesses while the game
	//is NOT won there are still tries

	while (!FBCGame.IsGameWon() && FBCGame.GetCurrentTry() <= MyMaxTries) {

		std::string Guess = GetValidGuess();
		BullCowCount NumOfBullsAndCows = FBCGame.SubmitValidGuess(Guess, FBCGame.MyHiddenWord);
		std::cout << "Bulls = " << NumOfBullsAndCows.Bulls << std::endl;
		std::cout << "Cows = " << NumOfBullsAndCows.Cows << std::endl;
		// increment the turn number
		FBCGame.MyCurrentTries++;
		RepeatGuess(Guess);
	}
	PrintGameSummary();

	/*constexpr int NumOfTries = 5;
	for (int count = 1;count <= NumOfTries; count++)
	{
		
		
	}*/
	
	// submit valid guess
	// print nums of bulls and cows
}

//display intro
void PrintIntro()
{
	int WORD_LENGTH = FBCGame.GetHiddenWordLength();

	std::cout << "Welcome to Bulls and Cows, a fun word game\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	return;
}

//loop continuously till user gives a valid guess
std::string GetValidGuess()
{
	while (true)
	{
		std::cout << "Try " << FBCGame.GetCurrentTry() << ", Enter your guess: ";
		std::string Guess = "";
		getline(std::cin, Guess);


		EGuessStatus Status = FBCGame.GetGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::OK:
			return Guess;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without a repeating letters." << std::endl;
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << FBCGame.GetHiddenWordLength() << " letter word." << std::endl;
			break;
		case EGuessStatus::Invalid_Char:
			std::cout << "Please enter a word without a repeating letters." << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase." << std::endl;
			break;
		default:
			break;
		}
	}
	
}

//repeat guess back to player
void RepeatGuess(std::string &Guess)
{
	
	std::cout << "Your guess is " << Guess << std::endl << std::endl;
}

bool AskToPlayAgain()
{
	
	std::cout << "Do You Want to Play Again With The Same Word?\n";
	std::string Answer = "";
	getline(std::cin, Answer);

	if (Answer[0] == 'y' || Answer[0] == 'Y')
	{
		std::cout << "That's the spirit!\n";
		return true;
		
	}
	std::cout << "Bye loser!\n";
	return false;
}

void PrintGameSummary() {

	if (FBCGame.IsGameWon()) {
		std::cout << "YOU WIN :) \n";
	}
	else {
		std::cout << "Better luck next time :) \n";
	}
}
