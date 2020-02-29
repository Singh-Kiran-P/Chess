#ifndef BOARD
#define BOARD
#include <string>
#include "pawn.h"
#include "player.h"

class Board {
    public:
        bool move(std::string currentpos, std::string moveTo, Player* player);
        void printBoard();
        bool checkWin();

        Pawn* getPiece(Position position);
        Pawn* getPiece(int x,int y);

        Board();
        ~Board();

    private:
        Pawn* m_board[8][8];
        bool checkRestrictions(int curr_x, int curr_y,int next_x,int next_y, Pawn* movingpiece, Pawn* nextpiece);
        void resetBoard();

};

#endif
