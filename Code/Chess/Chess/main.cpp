#include <iostream>
#include "board.h"
//#include "piece.h"
int main() {
	Board newBoard;
	newBoard.printBoard();

	newBoard.move("A3", "B2");

	newBoard.printBoard();

	return 1;

}
