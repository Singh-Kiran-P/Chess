#pragma once
#include "player.h"
#include "board.h"

class AIPlayer : public Player
{
public:
    void doMove(const QPoint &currPos, const QPoint &nextPos) override;
    AIPlayer(QString nameStr, QColor color, Board *board);

private:
    static const int m_attemptCount = 0;
};
