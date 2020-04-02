#include "game.h"
using namespace std;

Game::Game(bool vsAI)
{

	//    QString name1{}, name2{};
	//	cout << "Player 1's name: ";
	//	cin >> name1;

	//	if (!vsAI) {
	//		cout << "Player 2's name: ";
	//		cin >> name2;
	//	}
	//	else
	//		name2 = "AI";

	QColor color1{};
	QColor color2{};

	srand((unsigned int)time(nullptr)); // Use current time for random seed
    int coinflip{0}; //rand() % 2};
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

	m_player1 = new HumanPlayer{"player 1", color1, &m_board};
	if (!vsAI)
		m_player2 = new HumanPlayer{"player 2", color2, &m_board};
	else
		m_player2 = new AIPlayer{"AI", color2, &m_board};

	if (coinflip == 1)
	{
		//        cout << m_player1->name() << " is white, " << m_player2->name() << " is black." << endl;
		m_turn = m_player1;
	}
	else
	{
		//        cout << m_player2->name() << " is white, " << m_player1->name() << " is black." << endl;
		m_turn = m_player2;
	}

	m_player1->GenerateMoves();
	m_player2->GenerateMoves();
};

Game::~Game()
{
	delete m_player1;
	delete m_player2;
}

void Game::nextturn()
{
	if (m_turn == m_player1)
		m_turn = m_player2;
	else
		m_turn = m_player1;

    m_player1->GenerateMoves();
    m_player2->GenerateMoves();
};

void Game::run()
{
	bool win{};
	bool validmove{};

	// Creates the board and places the pawns
	//	printBoard(&m_board);
    QPoint curr{};
    QPoint next{};

    m_player1->GenerateMoves();
    m_player2->GenerateMoves();

	do
	{
		//		cout << "It's " << m_turn->name() << "'s turn" << endl;

		do
		{
            tuple<QPoint, QPoint> currMove = m_turn->getMove();

			curr = std::get<0>(currMove);
			next = std::get<1>(currMove);
			if ((validmove = m_board.Validmove(curr, next, m_turn->color())) == false)
			{
				//				InvalidMove(m_turn);
			}

		} while (!validmove); // If a move is invalid, a turn isn't skipped
		m_board.move(curr, next, true);

		//		clearScreen();
		//		printBoard(&m_board);
		win = ((m_player1->numOfMoves() == 0) || (m_player2->numOfMoves() == 0));
		if (!win)
			this->nextturn();
//		m_moves.addMove(m_board.getPiece(next)->getId(), m_board.getPiece(next)->getColor(), curr, next);

	} while (!win); //as long as no one has won, ask the next player for their move

	//	printWinner(m_turn);
//	char res{};
//	do
//	{
//		cout << "Show Logs? (y,n)";
//		cin >> res;
//		if (res == 'y')
//			m_moves.print();
//	} while (res != 'y' && res != 'n');
};
