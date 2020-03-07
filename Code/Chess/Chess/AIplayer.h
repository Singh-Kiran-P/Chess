#pragma once
#include "player.h"
#include "board.h"

class AIPlayer : public Player {
    public:
        Position moveFrom(Color playerColor);
        Position moveTo(Position currPos, Color playerColor);

        AIPlayer(string nameStr, Color color, Board& board);

    private:
        static const int m_attemptCount = 0;
        Board* m_board;
};
