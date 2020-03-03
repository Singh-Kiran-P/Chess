#ifndef GAME
#define GAME
#include <ctime>
#include <iostream>
#include "player.h"
#include "board.h"
#include "IO.h"


class Game {
	public:
		Game(bool vsAI);
		void nextturn() ;
		Player* currentPlayer();
		void run(Game & newGame);

	private:
		time_t m_time;
		Player m_player1;
		Player m_player2;
		Player* m_turn;

};

#endif
