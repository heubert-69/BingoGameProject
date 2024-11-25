#ifndef BINGO_GAME_HPP
#define BINGO_GAME_HPP

#include "bingo_card.hpp"
#include<vector>


class BingoGame
{
	public:
		BingoGame();
		void StartGame();
		int CallNumber();


	private:
		std::vector<int> CalledNumbers; //to get the numbers that were called by the random number generator
		BingoCard Players[4];

};



#endif //BINGO_GAME_HPP





