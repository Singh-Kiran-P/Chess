#include "board.h"
#include <iostream>

Pawn Board::getPiece(Position position) {
   int x = position.getx();
   int y = position.gety();

   return m_board[x][y];
}

void Board::move(std::string currentpos, std::string moveTo) {
    Position current;
    Position next;
    current.setpos(currentpos);
    next.setpos(moveTo);

    Pawn piece = getPiece(currentpos);
    if (piece.getName() != "." ) {
       m_board[moveTo.getx()][moveTo.gety()] = piece;
       Pawn emptypawn;
       m_board[currentpos.getx()][currentpos.gety()] = emptypawn;
   }
}

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
    std::cout << "\n" << std::endl;

}

//rest and init board
void Board::resetBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i == 1 )
			{
				Pawn p;
				p.setName("P");


				m_board[i][j] = p;

			}

		}
	}
}

Pawn Board::getPiece(int x, int y)
{
	return m_board[x][y];
}


Board::Board()
{
	resetBoard();
}
