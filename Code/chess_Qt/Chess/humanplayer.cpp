#include "humanplayer.h"

tuple<Position, Position> HumanPlayer::getMove()
{
    return m_Possiblemoves[0]; // TEMP
}

HumanPlayer::HumanPlayer(QString nameStr, QColor color, Board *board) : Player(nameStr, color, board){};
