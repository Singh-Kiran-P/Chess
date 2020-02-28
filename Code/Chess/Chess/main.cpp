#include <iostream>
#include "board.h"

int main() {
	Board newBoard;
	newBoard.printBoard();

	int count = 0;
	while (count < 5) {
		std::string curr;
		std::string next;
		std::cout << "Move which pawn? ";
		std:: cin >> curr;
		std::cout << "To where? ";
		std::cin >> next;

		count++;
		newBoard.move(curr, next);
		newBoard.printBoard();
	}
	// freeboard();
	return 1;

};
