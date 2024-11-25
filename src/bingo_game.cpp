#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
#include<cmath>
#include "../include/bingo_game.hpp"

BingoGame::BingoGame() {
	std::srand(std::time(0)); //starts the clock of the game (how much time it takes)
}

void BingoGame::StartGame() {
	bool WinnerFound = false;

	while(!WinnerFound && !CalledNumbers.size() < 25){
		int num = CallNumber();
		std::cout << "Number Called: " << num << std::endl;
		for(int i=0; i < 4; i++){
			if(Players[i].MarkNumber(num)){
				std::cout << "Player: " << i + 1 << " Marked " << num << ".\n";
			}
			if(Players[i].CheckWinningPattern()){
				std::cout << "Player: " << i + 1 << " Wins!!!!\n";
				Players[i].DisplayCard();
				WinnerFound = true;
				break;
			}
		}

		for(int i=0; i < 4; i++){
			std::cout << "\nPlayer " << i + 1 << "'s Card:\n";
			Players[i].DisplayCard();
		}
	}


	if(!WinnerFound){
		std::cout << "No Winner!\n";
	}
}

int BingoGame::CallNumber() {
	int num;
	do {
		num = rand() % 25 + 1; //to get a numbers from 1 to 75 thats not repeating
	} while(std::find(CalledNumbers.begin(), CalledNumbers.end(), num) != CalledNumbers.end());


	CalledNumbers.push_back(num); //appending numbers in the vector
	return num;
}
