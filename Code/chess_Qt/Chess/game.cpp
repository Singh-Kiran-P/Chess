#include "game.h"
using namespace std;

Game::Game(QString p1, QString p2, int vsAI)
{
	QColor color1{};
	QColor color2{};

	srand((unsigned int)time(nullptr)); // Use current time for random seed
    int coinflip{rand() % 2};
	if (coinflip == 1)
	{
		color1 = Qt::white;
        color2 = Qt::black;
	}
	else
	{
		color1 = Qt::black;
        color2 = Qt::white;
	}

    m_player1 = new HumanPlayer{p1, color1, m_board};
    if (vsAI == 0)
        m_player2 = new HumanPlayer{p2, color2, m_board};
	else
        m_player2 = new AIPlayer{"AI", color2, m_board};

    if (coinflip == 1)
        m_turn = m_player1;
    else
        m_turn = m_player2;
};

Game::~Game()
{
	delete m_player1;
	delete m_player2;
}

Player* Game::currentPlayer() {
    return m_turn;
}

void Game::nextturn()
{
	if (m_turn == m_player1)
		m_turn = m_player2;
	else
		m_turn = m_player1;

    if (auto AI = dynamic_cast<AIPlayer*>(m_turn))
        move();
};

void Game::move(const QPoint &currPos, const QPoint &nextPos) {
    m_player1->GenerateMoves();
    m_player2->GenerateMoves();

    if (m_player1->numOfMoves() == 0 ||m_player2->numOfMoves() == 0)
        emit gameOver();
    else {
         if(m_turn->doMove(currPos, nextPos)) {
            m_player1->GenerateMoves();
            m_player2->GenerateMoves();

            if (m_player1->numOfMoves() == 0 ||m_player2->numOfMoves() == 0)
                emit gameOver();

            nextturn();
         }
    }
}

void Game::setBoard(Board* board) {
    m_board = board;
    m_player1->setBoard(board);
    m_player2->setBoard(board);
}

