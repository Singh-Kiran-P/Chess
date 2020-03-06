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
	int coinflip{rand() % 2};
	if (coinflip == 1) {
		color1 = Color::White;
		color2 = Color::Black;
	}
	else {
		color1 = Color::Black;
		color2 = Color::White;
	}

	m_player1 = new HumanPlayer{ name1, color1 };


	if (!vsAI) {
		m_player2 = new HumanPlayer{ name2, color2 };
	}
	else {
		m_player2 = new AIPlayer{ name2, color2 };
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

Player* Game::currentPlayer() {
	return m_turn;
};

void Game::run() {
	bool checkwin;

	Board newBoard{}; // Creates the board and places the pawns
	newBoard.printBoard();

	Position curr{};
	Position next{};

	do {
		std::cout << "It's " << (this->currentPlayer())->name() << "'s turn" << std::endl;
		do {

			curr = currentPlayer()->moveFrom(newBoard, currentPlayer()->color());
			next = currentPlayer()->moveTo(curr, newBoard, currentPlayer()->color());

			} while (!newBoard.move(curr, next, (this->currentPlayer())->color())); // If a move is invalid, a turn isn't skipped

	        clearScreen();

			newBoard.printBoard();
			if ((checkwin = newBoard.checkWin()) == false)
				this->nextturn();

		} while (checkwin == false); //as long as no one has won, ask the next player for their move

		printWinner((this->currentPlayer())->name());
};
