#ifndef BOARD
#define BOARD
#define BOARD_SIZE 8
#include "pawn.h"
class Board {
    public:
        Pawn getPiece(Position position);
        void move(Position currentpos, Position moveTo);
        void printBoard();
        void resetBoard();
        Board();

    private:
        Pawn m_board[BOARD_SIZE][BOARD_SIZE];
};

#endif
