#include "game.h"
using namespace std;

void Game::initGame() {

    srand(time(nullptr)); // Use current time for random seed
    int coinflip = rand() % 2;

    if (coinflip = 1) {
        m_player1.setcolor(Color::White);
        cout << m_player1.name() << "is white, " << m_player2.name() << "is black." << endl;
        m_player2.setcolor(Color::Black);
        m_turn = &m_player1;
    }
    else {
        m_player1.setcolor(Color::Black);
        cout << m_player2.name() << "is white, " << m_player1.name() << "is black." << endl;
        m_player2.setcolor(Color::White);
        m_turn = &m_player2;
    }
};

void Game::nextturn() {
    if (m_turn == &m_player1)
        *m_turn = m_player2;
    else
        *m_turn = m_player1;
};
