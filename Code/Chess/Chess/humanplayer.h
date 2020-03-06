#pragma once
#include "player.h"

class HumanPlayer : public Player {
    public:
        Position moveFrom(Board& board, Color playerColor);
        Position moveTo(Position currPos, Board &board, Color playerColor);
        HumanPlayer(string nameStr, Color color);

    private:
        bool checkInput(std::string inputStr);
};
