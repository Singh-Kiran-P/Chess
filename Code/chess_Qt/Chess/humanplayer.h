#pragma once
#include "player.h"
#include "io.h"

class HumanPlayer : public Player
{
public:
    bool doMove(const QPoint &currPos, const QPoint &nextPos) override;
    HumanPlayer(QString nameStr, QColor color, Board *board);
};
