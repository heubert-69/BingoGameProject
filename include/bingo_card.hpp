#ifndef BINGO_CARD_HPP
#define BINGO_CARD_HPP

#include<iostream>
#include<ctime>
#include<cmath>
#include<vector>
#include<algorithm>




class BingoCard
{
	public:
		BingoCard();
		void GenerateCard();
		bool MarkNumber(int num);
		bool CheckWinningPattern();
		void DisplayCard();


	private:
		int Card[5][5];
		bool MarkedCard[5][5];

};


#endif //BINGO_CARD_HPP
