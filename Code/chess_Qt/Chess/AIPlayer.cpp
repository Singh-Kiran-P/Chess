#include "AIplayer.h"

bool AIPlayer::doMove(const QPoint &currPos, const QPoint &nextPos) {
    GenerateMoves();
    if (numOfMoves() != 0) {
        tuple<QPoint, QPoint> move = m_Possiblemoves[rand() % (m_Possiblemoves.size())];
        m_board->move(get<0>(move), get<1>(move), true);
        return true;
    }
    return false;
}

AIPlayer::AIPlayer(QString nameStr, Board *board) : Player(nameStr, board){};
