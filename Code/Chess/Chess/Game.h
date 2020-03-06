#pragma once
#include <ctime>
#include <iostream>
#include "humanplayer.h"
#include "aiplayer.h"
#include "board.h"
#include "IO.h"


class Game {
	public:
		Game(bool vsAI);
		~Game();

		void nextturn() ;
		Player* currentPlayer();
		void run();

	private:
		time_t m_time;
		Player* m_player1;
		Player* m_player2;
		Player* m_turn;

};
