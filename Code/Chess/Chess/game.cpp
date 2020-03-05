#include "game.h"
#include "io.h"
using namespace std;

Game::Game(bool vsAI) {

	string name1, name2;
	cout << "Player 1's name: ";
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

	clearScreen();

	srand((unsigned int)time(nullptr)); // Use current time for random seed
	int coinflip = rand() % 2;

	if (coinflip == 1) {
		m_player1.setcolor(Color::White);
		cout << m_player1.name() << " is white, " << m_player2.name() << " is black." << endl;
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
}
void Game::run(Game& newGame)
{
    clearScreen();
	bool checkwin;

	Board newBoard{}; // Creates the board and places the pawns
	newBoard.printBoard();

	std::string curr;
	std::string next;

	do {
		std::cout << "It's " << (newGame.currentPlayer())->name() << "'s turn" << std::endl;
		if ((newGame.currentPlayer())->get_is_ai()) {
			newBoard.AiMove(newGame.currentPlayer());
		}
        else {
		do {
			curr = "";
			next = "";
			do {
				std::cout << "Move which pawn? ";
				std::cin >> curr;
				curr[0] = toupper(curr[0]);
			} while (checkInput(curr) == false);

			do {
				std::cout << "To where? ";
				std::cin >> next;
				next[0] = toupper(next[0]);
			} while (checkInput(next) == false);

		} while (newBoard.move(curr, next, newGame.currentPlayer()) == false); // If a move is invalid, a turn isn't skipped

        clearScreen();

		}

		newBoard.printBoard();
		if ((checkwin = newBoard.checkWin()) == false)
			newGame.nextturn();

} while (checkwin == false); //as long as no one has won, ask the next player for their move

printWinner((newGame.currentPlayer())->name());
}
;
