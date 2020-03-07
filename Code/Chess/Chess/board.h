#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "humanplayer.h"
#include "pawn.h"
#include "TermColor.hpp"

class Board {
    public:

        bool move(Position current, Position next, Player* player);

        void printBoard() const;
        bool checkWin() const;

        Piece* getPiece(Position p);

        Board();
        ~Board();

    private:
        static const int SIZE_BOARD = 8;

        Piece* m_board[SIZE_BOARD][SIZE_BOARD];
        bool noBlockers(Position current, Position next) const;

};
