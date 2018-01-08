#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

int main () {
	PrintIntro();
	PlayGame();
	AskToPlayAgain();

	cout << endl;
	return 0;
}

void PrintIntro () {
	constexpr int WORD_LENGTH = 5;

	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}

void PlayGame () {
	constexpr int TRIES = 5;

	for (int i = 0; i < TRIES; i++) {
		string Guess = GetGuess();
		cout << "Your guess: " << Guess << endl;
	}
}

string GetGuess () {
	string Guess = "";

	cout << "\nEnter your guess: ";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain () {
	string Response = "";

	cout << "\nWould you like to play again? ";
	getline(cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}