#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main () {
	bool bPlayAgain;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain == true);

	std::cout << std::endl;
	return 0;
}

void PrintIntro () {
	constexpr int32 WORD_LENGTH = 5;

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}

void PlayGame () {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// TODO change from for loop to while
	for (int32 i = 1; i <= MaxTries; i++) {
		FText Guess = GetGuess(); // TODO make loop checking valid

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << std::endl;
	}

	// TODO add a game summary
}

FText GetGuess () {
	FText Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();

	std::cout << std::endl << "Try " << CurrentTry << " - Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain () {
	FText Response = "";

	std::cout << "\nWould you like to play again (y/n)? ";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return (Response[0] == 'y' || Response[0] == 'Y');
}
