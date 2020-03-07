#pragma once
#include "player.h"

class HumanPlayer : public Player {
    public:
        Position moveFrom(Color playerColor);
        Position moveTo(Position currPos, Color playerColor);
        HumanPlayer(string nameStr, Color color);

    private:
        bool checkInput(std::string inputStr);
};
