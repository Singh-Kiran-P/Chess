#pragma once
#include <ctime>
#include <iostream>
#include "humanplayer.h"
#include "AIplayer.h"
#include "board.h"
//#include "moves.h"
#include "IO.h"

class Game
{
public:
	Game(bool vsAI);
	~Game();

	void nextturn();
	Player *currentPlayer();
	void run();

	void printMoves();

private:
	Board m_board;
	Player *m_player1;
	Player *m_player2;
	Player *m_turn;
//	Moves m_moves;
};
