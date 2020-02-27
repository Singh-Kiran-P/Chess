#include "game.h"
using namespace std;

void Game::initGame() {

    srand(time(nullptr)); // Use current time for random seed
    int coinflip = randint(0, 1);

    if (coinflip = 1) {
        m_player1.setcolor(White);
        m_player2.setcolor(Black);
        m_turn = m_player1;
    }
    else {
        m_player1.setcolor(Black);
        m_player2.setcolor(White);
        m_turn = m_player2;
    }
};

void Game::nextturn() {
    if (m_turn = m_player1)
        m_turn = m_player2;
    else
        m_turn = m_player1;
};
