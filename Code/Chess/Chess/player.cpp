#include "player.h"

Color Player::color() const{
    return m_color;
};

std::string Player::name()const {
    return m_playername;
};

Player::Player(string nameStr, Color color) : m_playername{ nameStr }, m_color{ color } {};