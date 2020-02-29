#ifndef GAME
#define GAME
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "player.h"
#include "board.h"


class Game {
	public:
		Game();
		void nextturn();
		Player* currentPlayer();

	private:
		time_t m_time;
		Player m_player1;
		Player m_player2;
		Player* m_turn;

};

#endif
