#include "player.h"

QColor Player::color() const
{
    return m_color;
};

QString Player::name() const
{
    return m_playername;
};

void Player::GenerateMoves()
{
    Position currpos;
    Position nextpos;

    m_Possiblemoves.clear();
    for (int currentx = 0; currentx < 8; currentx++)
    {
        for (int currenty = 0; currenty < 8; currenty++)
        {
            for (int nextx = 0; nextx < 8; nextx++)
            {
                for (int nexty = 0; nexty < 8; nexty++)
                {
                    currpos.setpos(currentx, currenty);
                    nextpos.setpos(nextx, nexty);
                    if (m_board->Validmove(currpos, nextpos, m_color))
                        m_Possiblemoves.push_back(tuple<Position, Position>{currpos, nextpos});
                }
            }
        }
    }
};

Player::Player(QString nameStr, QColor color, Board *board) : m_playername{nameStr}, m_color{color}, m_board{board} {};
