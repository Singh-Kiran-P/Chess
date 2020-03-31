#pragma once
#include "player.h"
#include "io.h"

class HumanPlayer : public Player {
    public:
        Position moveFrom(Color playerColor);
        Position moveTo(Position currPos, Color playerColor);
        HumanPlayer(string nameStr, Color color);
};
