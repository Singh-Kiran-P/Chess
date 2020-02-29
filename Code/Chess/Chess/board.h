#ifndef BOARD
#define BOARD
#include <string>
#include "pawn.h"
#include "player.h"
const int SIZE_BOARD = 8;
class Board {
    public:
        bool move(Position current, Position next, Player* player);
        bool moveStr(std::string currentpos, std::string moveTo, Player* player);
        void AiMove(Player* player);

        void printBoard();
        bool checkWin();

        Pawn* getPiece(Position position);
        Pawn* getPiece(int x,int y);

        Board();
        ~Board();

    private:
        Pawn* m_board[SIZE_BOARD][SIZE_BOARD];
        bool checkRestrictions(int curr_x, int curr_y,int next_x,int next_y, Pawn* movingpiece, Pawn* nextpiece);
        void resetBoard();

};

#endif
