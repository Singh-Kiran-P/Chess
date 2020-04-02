#pragma once
#include "player.h"
#include "io.h"

class HumanPlayer : public Player
{
public:
    HumanPlayer(QString nameStr, QColor color, Board *board);
};
