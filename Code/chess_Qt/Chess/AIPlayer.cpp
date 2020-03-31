#include "AIplayer.h"

tuple<Position, Position> AIPlayer::getMove() {
    return m_Possiblemoves[rand() % (m_Possiblemoves.size() - 1)];
};

AIPlayer::AIPlayer(string nameStr, Color color, Board* board) : Player(nameStr, color, board) {};
