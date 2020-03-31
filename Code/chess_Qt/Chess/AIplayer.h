#pragma once
#include "player.h"
#include "board.h"

class AIPlayer : public Player {
    public:
        tuple <Position, Position> getMove();

        AIPlayer(string nameStr, Color color, Board* board);

    private:
        static const int m_attemptCount = 0;
};
