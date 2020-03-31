#pragma once
#include "player.h"
#include "io.h"

class HumanPlayer : public Player {
    public:
        tuple <Position, Position> getMove();

        HumanPlayer(string nameStr, Color color, Board* board);
};
