#include "game.h"
using namespace std;

Game::Game(const QString &p1,const  QString &p2, int vsAI)
{
    Player* player1 = new HumanPlayer{p1, m_board};
    Player* player2;;
    if(vsAI == 1) {
        player2 = new AIPlayer{"AI", m_board};
    }
    else player2 = new HumanPlayer{p2, m_board};

    srand((unsigned int)time(nullptr)); // Use current time for random seed
    int coinflip{rand() % 2};
    if (coinflip == 1) {
        m_whiteplayer = player1;
        m_blackplayer = player2;
	}
    else {
        m_whiteplayer = player2;
        m_blackplayer = player1;
    }
    m_whiteplayer->setColor(Qt::white);
    m_blackplayer->setColor(Qt::black);

    m_turn = m_whiteplayer;
};

Game::~Game()
{
    delete m_whiteplayer;
    delete m_blackplayer;
}

Player* Game::currentPlayer() {
    return m_turn;
}

void Game::nextturn()
{
    if (m_turn == m_whiteplayer)
        m_turn = m_blackplayer;
	else
        m_turn = m_whiteplayer;

    if (auto AI = dynamic_cast<AIPlayer*>(m_turn))
        move();
};

void Game::move(const QPoint &currPos, const QPoint &nextPos) {
    m_whiteplayer->GenerateMoves();
    m_blackplayer->GenerateMoves();

    if (m_whiteplayer->numOfMoves() == 0 ||m_blackplayer->numOfMoves() == 0)
        emit gameOver();
    else {
         if (m_turn->doMove(currPos, nextPos)) {

            m_whiteplayer->GenerateMoves();
            m_blackplayer->GenerateMoves();

            if (m_whiteplayer->numOfMoves() == 0 ||m_blackplayer->numOfMoves() == 0) {
                emit gameOver();
                return;
            }
            nextturn();
        }
    }
}

void Game::setBoard(Board* board) {
    m_board = board;
    m_whiteplayer->setBoard(board);
    m_blackplayer->setBoard(board);
}

