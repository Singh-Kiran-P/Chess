#pragma once
#include "player.h"
#include "io.h"

class HumanPlayer : public Player
{
public:
    tuple<QPoint, QPoint> getMove();

    HumanPlayer(QString nameStr, QColor color, Board *board);
};
