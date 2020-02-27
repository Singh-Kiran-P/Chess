#include <iostream>
#include "pawn.h"
//#include "piece.h"
int main() {

	Pawn m_board[1][1];

	Pawn x;
	
	m_board[0][0] = x;
	std::cout << (m_board[0][0]).getName();
	return 1;
	
}