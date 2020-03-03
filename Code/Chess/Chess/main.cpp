#include <iostream>
#include "game.h"
#include "IO.h"

int main() {
	printLogo();
	bool gametype = checkChoice();
	bool checkwin;

	Game newGame{gametype}; // Creates both player objects, randomly assigns them their color

	Board newBoard{}; // Creates the board and places the pawns
	newBoard.printBoard();

	std::string curr;
	std::string next;

	do {
		std::cout << "It's " << (newGame.currentPlayer())->name() << "'s turn" << std::endl;
		if ((newGame.currentPlayer())->get_is_ai())
			newBoard.AiMove(newGame.currentPlayer());
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

			} while (newBoard.move( curr , next, newGame.currentPlayer()) == false); // If a move is invalid, a turn isn't skipped

		}

		newBoard.printBoard();
		if ((checkwin = newBoard.checkWin()) == false)
		newGame.nextturn();

	} while (checkwin == false); //as long as no one has won, ask the next player for their move

	printWinner((newGame.currentPlayer())->name());
	return 1;
};
