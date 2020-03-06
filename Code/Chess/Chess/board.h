#pragma once
#include <string>
#include "pawn.h"
#include "player.h"


class Board {
    public:

        bool move(Position current, Position next, Player* player);
        bool move(std::string currentpos, std::string moveTo, Player* player);
        void AiMove(Player* player);

        void printBoard() const;
        bool checkWin() const;

        Board();
        ~Board();

    private:
        static const int SIZE_BOARD = 8;

        Piece* m_board[SIZE_BOARD][SIZE_BOARD];
        bool validChoice(int xpos, int ypos, Color playercolor);
        bool noBlockers(Position current, Position next) const;

};
