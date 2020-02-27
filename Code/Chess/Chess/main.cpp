#include <iostream>
#include "board.h"
//#include "piece.h"
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
	return 1;

};
