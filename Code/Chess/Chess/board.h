#ifndef BOARD
#define BOARD
#define BOARD_SIZE 8
#include "pawn.h"
class Board {
    public:
        Pawn getPiece(Position position);
        void move(std::string currentpos, std::string moveTo);
        void printBoard();
        void resetBoard();
        Pawn getPiece(int x,int y);
        void move(Position moveTo);
        Board();

    private:
        Pawn m_board[BOARD_SIZE][BOARD_SIZE];
};

#endif
