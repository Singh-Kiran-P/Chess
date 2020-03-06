#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "pawn.h"
#include "TermColor.hpp"

class Board {
    public:
        static const int SIZE_BOARD = 8;

        bool move(Position current, Position next, Color playerColor);

        void printBoard() const;
        bool checkWin() const;

        Piece* getPiece(Position p);

        Board();
        ~Board();

    private:
        Piece* m_board[SIZE_BOARD][SIZE_BOARD];
        bool noBlockers(Position current, Position next) const;

};
