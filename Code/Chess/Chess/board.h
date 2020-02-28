#ifndef BOARD
#define BOARD
#include <string>
#include "pawn.h"

class Board {
    public:
        bool move(std::string currentpos, std::string moveTo,Color playerColor);
        void printBoard();
        Pawn* getPiece(Position position);
        Pawn* getPiece(int x,int y);
        void move(Position moveTo);
        Board();
        ~Board();

    private:
        Pawn* m_board[8][8];
        bool checkRestrictions(int curr_x, int curr_y,int next_x,int next_y, Pawn* movingpiece, Pawn* nextpiece);
        void resetBoard();

};

#endif
