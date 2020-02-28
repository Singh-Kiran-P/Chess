#include "board.h"
#include <iostream>

Pawn* Board::getPiece(Position position) {
   int x = position.getx();
   int y = position.gety();

   return m_board[x][y];
}

bool Board::checkRestrictions(int curr_x, int curr_y,int next_x,int next_y, Pawn* p)
{
	//Pawn p = m_board[curr_x][curr_y];
	if (p->firtsTurn())
	{
		if (curr_y ==next_y && (next_x == curr_x+2) || (next_x == curr_x + 1))
		{
			p->setfirstTurnFalse();
			return true;
		}
	}
	else if ((next_x == curr_x + 1)) {
		return true;
	}
	return false;
}


void Board::move(std::string currentpos, std::string moveTo) {
    Position current;
    Position next;
    current.setpos(currentpos);
    next.setpos(moveTo);

    Pawn* piece = getPiece(current.getx(), current.gety());
		if (checkRestrictions(current.getx(), current.gety(), next.getx(), next.gety(), piece)) {
			m_board[next.getx()][next.gety()] = piece;
			m_board[current.getx()][current.gety()] = nullptr;
		}



}

void Board::printBoard()
{
	for (int i = 0; i < 8; i++)
	{
	std::cout << i <<" |";
		for (int j = 0; j < 8; j++)
		{
			if (m_board[i][j] != nullptr) {
				Pawn* temp_pawn = m_board[i][j];
				std::cout << temp_pawn->getId() << ' ';
			}
            else
                std::cout << ". ";
		}
		std::cout << '\n';
	}
    std::cout << "   _______________" << std::endl;
	std::cout << "   A B C D E F G H" << std::endl;
};

//rest and init board
void Board::resetBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
            if (i == 1 || i == 6)
			{

				Pawn* p_ptr{new Pawn{}};
				m_board[i][j] = p_ptr;
				p_ptr->setId('P');
				p_ptr->setColor(Color::Black);
            }
            else
                m_board[i][j] = nullptr;
		}
	}
};

Pawn* Board::getPiece(int x, int y)
{
	return m_board[x][y];
}

Board::Board()
{
	resetBoard();
};
