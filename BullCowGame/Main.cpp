#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
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
	constexpr int WORD_LENGTH = 5;

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}

void PlayGame () {
	int MaxTries = BCGame.GetMaxTries();

	for (int i = 1; i <= MaxTries; i++) {
		std::string Guess = GetGuess();
		std::cout << "Your guess: " << Guess << std::endl;
	}
}

std::string GetGuess () {
	std::string Guess = "";
	int CurrentTry = BCGame.GetCurrentTry();

	std::cout << std::endl << "Try " << CurrentTry << " - Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain () {
	std::string Response = "";

	std::cout << "\nWould you like to play again (y/n)? ";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return (Response[0] == 'y' || Response[0] == 'Y');
}
