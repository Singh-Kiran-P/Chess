#include <iostream>
#include "board.h"
//#include "piece.h"
int main() {
	Board newBoard;
	newBoard.printBoard();

	newBoard.move("B0", "C0");

	newBoard.printBoard();

	return 1;

}
