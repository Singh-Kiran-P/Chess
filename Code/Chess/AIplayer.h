#pragma once
#include "player.h"
#include "board.h"

class AIPlayer : public Player
{
public:
    bool doMove(const QPoint &currPos, const QPoint &nextPos) override;
    AIPlayer(QString nameStr, Board *board);
};
