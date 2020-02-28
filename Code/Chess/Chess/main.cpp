#include <iostream>
#include "Game.h"
#include "TermColor.hpp"

bool checkInput(std::string inputStr);

int main() {
	Game newGame;
	newGame.initGame();

	Board newBoard{};
	newBoard.printBoard();

		int resultMove;
		std::string curr = "";
		std::string next = "";

		do {
			std::cout << "It's " << (newGame.currentPlayer())->name() << "'s turn" << std::endl;

			curr = "";
			next = "";

			do {
				std::cout << "Move which pawn? ";
				std::cin >> curr;

			} while (checkInput(curr) == false);

			do {
				std::cout << "To where? ";
				std::cin >> next;
			} while (checkInput(next) == false);

			resultMove = newBoard.move(curr, next, newGame.currentPlayer());

			if (resultMove != -1) { //move returns -1 if someone won the game
				newBoard.printBoard();
				newGame.nextturn();
			}

		} while (resultMove != -1);

	return 1;
};

bool checkInput(std::string  inputStr) {
	try {
		char letter = inputStr[0];
		int num = std::stoi(inputStr.substr(1)) - 1;
		if (('A' <= letter <= 'H') && (1 <= num <= 8))
			return true;
	}
	catch (const std::exception&) {
		std::cout << termcolor::red << "Invaild input" << termcolor::white<<std::endl;
	}
	return false;
};
