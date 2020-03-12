#pragma once
#include <ctime>
#include <iostream>
#include "humanplayer.h"
#include "aiplayer.h"
#include "board.h"
#include "IO.h"
#include "moves.h"

class Game {
public:
	Game(bool vsAI);
	~Game();

		void nextturn() ;
		void run();

private:
	Board m_board;
	Player* m_player1;
	Player* m_player2;
	Player* m_turn;
	Moves m_moves;
};

