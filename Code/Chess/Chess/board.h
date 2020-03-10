#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "humanplayer.h"
#include "TermColor.hpp"
#include "pawn.h"
#include "rook.h"
#include "king.h"
#include "queen.h"
#include "knight.h"
#include "bishop.h"
#include "player.h"
class Board {
public:

	bool move(Position current, Position next, Player* player);
  
	void printBoard() const;
	Piece* getPiece(Position p);

    bool checkWin();

	Board();
	~Board();
protected:
	bool winEndGame;

private:
	static const int SIZE_BOARD = 8;

	Piece* m_board[SIZE_BOARD][SIZE_BOARD];
	bool noBlockers(Position current, Position next) const;

};
