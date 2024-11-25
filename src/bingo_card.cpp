#include "../include/bingo_card.hpp"
#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>

BingoCard::BingoCard()
{
	GenerateCard();
	for(int i=0; i < 5; i++){
		for(int x=0; x < 5; x++){
			MarkedCard[i][x] = false; //to indicate that no numbers were found on the number generator function
		}
	}
}

void BingoCard::GenerateCard()
{
	std::vector<int> numbers;
	for(int i=0; i <= 25; i++){
		numbers.push_back(i);
		std::random_shuffle(numbers.begin(), numbers.end());
	}

	int index = 0; //to get the location of which number is the algorithm at
	for(int i=0; i < 5; i++){
		for(int x=0; x < 5; x++){
			Card[i][x] = numbers[index++];
		}
	}
}

bool BingoCard::MarkNumber(int num)
{
	for(int i=0; i < 5; i++){
		for(int x=0; x < 5; x++){
			if(Card[i][x] == num){
				MarkedCard[i][x] = true;
				return true;
			}
		}
	}
	return false;
}

bool BingoCard::CheckWinningPattern()
{
	for(int i=0; i < 5; i++){
		bool RowWin = true, ColWin = true; //making it false if no winning patterns are detected in a row or col
		for(int x=0; x < 5; x++){
			if(!MarkedCard[i][x]){
				RowWin = false; //if not a winning combination
			}
			if(!MarkedCard[x][i]){
				ColWin = false; //if not a winning combination
			}
		}
		if(RowWin || ColWin){
			return true; //if row or col is a winning pattern then someone is a winner
		}
	}

	bool Diag_1 = true, Diag_2 = true; //checking if a diagonal is a winning combination if no row or col is a winning combination
	for(int i=0; i < 5; i++){
		if(!MarkedCard[i][i]){
			Diag_1 = false;
		}
		if(!MarkedCard[i][4-i]){
			Diag_2 = false;
		}
	}
	return Diag_1 || Diag_2;
}

void BingoCard::DisplayCard()
{
	std::cout << " C  H  A  I  N\n";
	for(int i=0; i < 5; i++){
		for(int x=0; x < 5; x++){
			if(MarkedCard[i][x]){
				std::cout << " X ";
			}
			else {
				std::cout << (Card[i][x] < 10 ? " " : "") << Card[i][x] << " ";
			}
		}
		std::cout << std::endl;
	}

}
