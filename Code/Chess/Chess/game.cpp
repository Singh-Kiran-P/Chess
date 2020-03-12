#include "game.h"
#include "io.h"
using namespace std;

Game::Game(bool vsAI) {

	string name1{}, name2{};
	cout << "Player 1's name: ";
	cin >> name1;

	if (!vsAI) {
		cout << "Player 2's name: ";
		cin >> name2;
	}
	else
		name2 = "AI";

	clearScreen();

	Color color1{};
	Color color2{};

	srand((unsigned int)time(nullptr)); // Use current time for random seed
	int coinflip{ rand() % 2 };
	if (coinflip == 1) {
		color1 = Color::White;
		color2 = Color::Black;
	}
	else {
		color1 = Color::Black;
		color2 = Color::White;
	}

	if (name1 == "AI2")
		m_player1 = new AIPlayer{ name1, color1,m_board };

	else
		m_player1 = new HumanPlayer{ name1, color1 };


	if (!vsAI) {
		m_player2 = new HumanPlayer{ name2, color2 };
	}
	else {
		m_player2 = new AIPlayer{ name2, color2, m_board };
	}



	if (coinflip == 1) {
		cout << m_player1->name() << " is white, " << m_player2->name() << " is black." << endl;
		m_turn = m_player1;
	}
	else {
		cout << m_player2->name() << " is white, " << m_player1->name() << " is black." << endl;
		m_turn = m_player2;
	}

};

Game::~Game() {
	delete m_player1;
	delete m_player2;
}

void Game::nextturn() {
	if (m_turn == m_player1)
		m_turn = m_player2;
	else
		m_turn = m_player1;
};
void Game::run() {
	bool win{};
	bool validmove{};

	// Creates the board and places the pawns
	printBoard(&m_board);
	Position curr{};
	Position next{};
	do {
		std::cout << "It's " << m_turn->name() << "'s turn" << std::endl;
		do {
			curr = m_turn->moveFrom(m_turn->color());
			next = m_turn->moveTo(curr, m_turn->color());
			if ((validmove = m_board.move(curr, next, m_turn)) == false)
				InvalidMove(m_turn);

		} while (!validmove); // If a move is invalid, a turn isn't skipped

		clearScreen();
		printBoard(&m_board);
		if ((win = m_board.checkWin()) == false)
			this->nextturn();

		m_moves.addMove(m_board.getPiece(next)->getId();, _board.getPiece(next)->getColor();, curr, next);

	} while (win == false); //as long as no one has won, ask the next player for their move
	printWinner((m_turn)->name());
	cout << "Show Logs (y,n)";
	char res;
	cin >> res;
	if (res == 'y')
		m_moves.print();
};

