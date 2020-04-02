#include "AIplayer.h"

tuple<QPoint, QPoint> AIPlayer::getMove()
{
    return m_Possiblemoves[rand() % (m_Possiblemoves.size() - 1)];
};

AIPlayer::AIPlayer(QString nameStr, QColor color, Board *board) : Player(nameStr, color, board){};
