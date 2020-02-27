#include "board.h"
#include <iostream>

void Board::printBoard()
{
	for (int i = 0; i < 8; i++)
	{
		if (i == 0)std::cout << "A| ";
		if (i == 1)std::cout << "B| ";
		if (i == 2)std::cout << "C| ";
		if (i == 3)std::cout << "D| ";
		if (i == 4)std::cout << "E| ";
		if (i == 5)std::cout << "F| ";
		if (i == 6)std::cout << "G| ";
		if (i == 7)std::cout << "H| ";


		for (int j = 0; j < 8; j++)
		{

			std::cout << m_board[i][j].getName() << " ";
		}
		std::cout << "\n";
	}
	std::cout << "   ";

	for (int i = 0; i < 8; i++)
	{
		std::cout << i << " ";
	}

}

//rest and init board
void Board::resetBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i == 1 || i == 6)
			{
				Pawn p;
				p.setName("P");

				m_board[i][j] = p;

			}

		}
	}
}

Board::Board()
{
	resetBoard();
}
