#pragma once
#include "player.h"

class AIPlayer : public Player {
    public:
        Position moveFrom(Board& board, Color playerColor);
        Position moveTo(Position currPos, Board &board, Color playerColor);

        AIPlayer(string nameStr, Color color);
    private:
        static const int m_attemptCount = 0;
};
