#pragma once
#include <string>

class FBullCowGame {
public:
	void Reset(); // TODO make a richer return value
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool IsCheckValid(std::string);
private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};
