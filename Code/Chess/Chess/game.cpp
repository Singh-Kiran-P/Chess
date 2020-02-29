#include "game.h"
using namespace std;

Game::Game(bool vsAI) {

    string name1, name2;
    cout << "Player 1's name: "  ;
    cin >> name1;
    m_player1.setName(name1);
    m_player1.set_ai(false);

    if (!vsAI) {
    cout << "Player 2's name: ";
    cin >> name2;
    m_player2.setName(name2);
    m_player2.set_ai(false);
    }

    else {
        m_player2.setName("AI");
        m_player2.set_ai(true);
    }

    srand((unsigned int) time(nullptr)); // Use current time for random seed
    int coinflip = rand() % 2;

    if (coinflip == 1) {
        m_player1.setcolor(Color::White);
        cout <<endl<< m_player1.name() << " is white, " << m_player2.name() << " is black." << endl;
        m_player2.setcolor(Color::Black);
        m_turn = &m_player1;
    }
    else {
        m_player1.setcolor(Color::Black);
        cout << m_player2.name() << " is white, " << m_player1.name() << " is black." << endl;
        m_player2.setcolor(Color::White);
        m_turn = &m_player2;
    }
};

void Game::nextturn() {
    if (m_turn == &m_player1)
        m_turn = &m_player2;
    else
        m_turn = &m_player1;
};

Player* Game::currentPlayer() {
    return m_turn;
};
