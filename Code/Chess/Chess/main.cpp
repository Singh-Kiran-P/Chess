#include <iostream>
#include "Game.h"
#include "TermColor.hpp"

bool checkInput(std::string inputStr);

int main() {
	Game newGame;
	newGame.initGame();

	Board newBoard = newGame.getBoard();
	newBoard.printBoard();

	while (true) {

		std::cout << "It's " << (newGame.currentPlayer())->name() << "'s turn" << std::endl;

		std::string curr = "";
		std::string next = "";
		do {
			do {
				std::cout << "Move which pawn? ";
				std::cin >> curr;

			} while (checkInput(curr) == false);

			do {
				std::cout << "To where? ";
				std::cin >> next;
			} while (checkInput(next) == false);

		} while (newBoard.move(curr, next, (newGame.currentPlayer())->color()) == false);

		newBoard.printBoard();
		newGame.nextturn();
	}
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
}
