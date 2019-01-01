#pragma once
#include <string>

struct BullCowCount 
{
	int Bulls = 0;
	int Cows = 0;


};
enum class EGuessStatus 
{

	OK,
	Not_Isogram,
	Not_Lowercase,
	Wrong_Length,
	Invalid_Char,



};
class FBullCowGame
{
public:
	
	FBullCowGame(); //constructor
	int NumOfTries() const;
	bool PlayAgain() const;
	int LengthOfWord() const;
	bool IsGameWon() const;
	int GetCurrentTry() const;
	int GetHiddenWordLength() const;
	EGuessStatus GetGuessValidity(std::string Guess);

	void Reset(); //make a more rich return value
	

	// counts bulls and cows and increases try and assume valid 
	BullCowCount SubmitValidGuess(std::string Guess, std::string HiddenWord);

	// submit valid guess, increase turn number

	std::string MyHiddenWord;
	int MyCurrentTries;
private: //see constructor for intialization
	int MyMaxTries; //see constructor for intialization
	bool IsGame1;
	bool IsIsogram(std::string Guess);
	bool IsLower(std::string Guess);

};