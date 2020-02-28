#include <iostream>
#include "board.h"

int main() {
	Board newBoard;
	newBoard.printBoard();
	while (true) {
		std::string curr;
		std::string next;
		std::cout << "Move which pawn? ";
		std:: cin >> curr;
		std::cout << "To where? ";
		std::cin >> next;

		newBoard.move(curr, next);
		newBoard.printBoard();
	}
	// freeboard();
	return 1;

};
