#include "humanplayer.h"

bool HumanPlayer::doMove(const QPoint &currPos, const QPoint &nextPos) {
    GenerateMoves();
    if (numOfMoves() != 0 && m_Possiblemoves.contains(make_tuple(currPos, nextPos))) {
        m_board->move(currPos, nextPos, true);
        return true;
    }
    return false;
}

HumanPlayer::HumanPlayer(QString nameStr, QColor color, Board *board) : Player(nameStr, color, board){};
