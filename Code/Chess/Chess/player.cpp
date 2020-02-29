#include "player.h"

void Player::setcolor(Color color) {
    m_color = color;
};

Color Player::color() {
    return m_color;
};

void Player::setName(std::string name) {
    m_playername = name;
};

std::string Player::name() {
    return m_playername;
};

bool Player::is_ai() {
    return m_is_ai;
};

void Player::set_ai(bool ai) {
    m_is_ai = ai;
};
