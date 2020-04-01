#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "pawn.h"
#include "rook.h"
#include "king.h"
#include "queen.h"
#include "knight.h"
#include "bishop.h"

class Board {
	public:
        bool Validmove(Position current, Position next, QColor playercolor);
        void move(Position current, Position next, bool realMove = false);

		void printBoard() const;
		Piece* getPiece(Position p);


		void changePawn(Pawn*);

		Board();
		~Board();

	private:
		static const int SIZE_BOARD = 8;

		Piece* m_board[SIZE_BOARD][SIZE_BOARD];
        Piece* FindKing(QColor color);
		bool SafePos(Piece* movingpiece, Position next);
		bool noBlockers(Position current, Position next) const;

};
