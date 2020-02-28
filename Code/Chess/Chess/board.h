#ifndef BOARD
#define BOARD
#define BOARD_SIZE 8
#include <string>
#include "pawn.h"

class Board {
    public:
        void move(std::string currentpos, std::string moveTo);
        void printBoard();
        Pawn* getPiece(Position position);
        Pawn* getPiece(int x,int y);
        void move(Position moveTo);
        Board();


    private:
        Pawn* m_board[BOARD_SIZE][BOARD_SIZE];
        bool checkRestrictions(int curr_x, int curr_y, int next_x, int next_y, Pawn* p);
        void resetBoard();

};

#endif
