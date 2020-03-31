#include "player.h"

Color Player::color() const{
    return m_color;
};

std::string Player::name()const {
    return m_playername;
};

void Player::GenerateMoves() {
    Position currpos;
    Position nextpos;
    for (int currentx = 0; currentx < 8; currentx++) {
        for (int currenty = 0; currenty < 8; currenty++) {
            for (int nextx = 0; nextx < 8; nextx++) {
                for (int nexty = 0; nexty < 8; nexty++) {
                    currpos.setpos(currentx, currenty);
                    nextpos.setpos(nextx, nexty);
                    if (m_board->Validmove(currpos, nextpos, m_color))
                        m_Possiblemoves.push_back(std::make_tuple(currpos, nextpos));
                }
            }
        }
    }
};

Player::Player(string nameStr, Color color, Board* board) : m_playername{ nameStr }, m_color{ color }, m_board{board} {};
