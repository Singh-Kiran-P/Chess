#include "player.h"

QColor Player::color() const
{
    return m_color;
};

QString Player::name() const
{
    return m_playername;
};

bool Player::possibleMove(const tuple<QPoint, QPoint> &move) {
    return (m_Possiblemoves.contains(move));
}

void Player::setBoard(Board *board) {
    m_board = board;
}

void Player::GenerateMoves()
{
    QPoint currpos;
    QPoint nextpos;

    m_Possiblemoves.clear();
    for (int currenty = 0; currenty < 8; currenty++)
    {
        for (int currentx= 0; currentx < 8; currentx++)
        {
            for (int nexty = 0; nexty < 8; nexty++)
            {
                for (int nextx = 0; nextx < 8; nextx++)
                {
                    currpos.setX(currentx);
                    currpos.setY(currenty);
                    nextpos.setX(nextx);
                    nextpos.setY(nexty);
                    if (m_board->Validmove(currpos, nextpos, m_color))
                        m_Possiblemoves.append(tuple<QPoint, QPoint>{currpos, nextpos});
                }
            }
        }
    }
};

Player::Player(QString nameStr, QColor color, Board *board) : m_playername{nameStr}, m_color{color}, m_board{board} {};
