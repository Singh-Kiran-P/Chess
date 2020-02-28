#include "board.h"
#include <iostream>

Pawn* Board::getPiece(Position position) {
   int x = position.getx();
   int y = position.gety();

   return m_board[x][y];
};

bool Board::checkRestrictions(int curr_x, int curr_y,int next_x,int next_y, Pawn* movingpiece, Pawn* nextpiece)
{
	if (movingpiece->getColor() == Color::White) {
        int max_delta_x = -1;
        if (movingpiece->firtsTurn()) {
            max_delta_x--;
            movingpiece->setfirstTurnFalse();
        }
        if (curr_y == next_y && (max_delta_x <= (next_x - curr_x) && (next_x - curr_x) < 0)) {
            if (nextpiece == nullptr)
                return true;
            else {
            std::cout << "\nInvalid move" << std::endl;;
                return false;
            }
        }
        else if (abs(curr_y - next_y) == 1 && (next_x - curr_x) == -1) {
            if (movingpiece->getColor() != nextpiece->getColor()) {
                delete nextpiece;
                return true;
            }
            else {
            std::cout << "\nInvalid move" << std::endl;;
                return false;
            }
        }
    }

    else if (movingpiece->getColor() == Color::Black) {
        int max_delta_x = 1;
        if (movingpiece->firtsTurn()) {
            max_delta_x++;
            movingpiece->setfirstTurnFalse();
        }
            if (curr_y == next_y && (0 < (next_x - curr_x) && (next_x - curr_x) <= max_delta_x)) {
                if (nextpiece == nullptr)
                    return true;
                else {
                std::cout << "\nInvalid move" << std::endl;
                    return false;
                }
            }
        else if (abs(curr_y - next_y) == 1 && (next_x - curr_x) == 1) {
            if (movingpiece->getColor() != nextpiece->getColor()) {
                delete nextpiece;
                return true;
            }
            else {
            std::cout << "\nInvalid move" << std::endl;
                return false;
            }
        }
    }
    std::cout << "\nInvalid move" << std::endl;
    return false;
};

void Board::move(std::string currentpos, std::string moveTo) {
    Position current;
    Position next;
    current.setpos(currentpos);
    next.setpos(moveTo);

    Pawn* movingpiece = getPiece(current.getx(), current.gety());
    if (movingpiece == nullptr)
        return;

    Pawn* nextpiece = getPiece(next.getx(), next.gety());
		if (checkRestrictions(current.getx(), current.gety(), next.getx(), next.gety(), movingpiece, nextpiece)) {
			m_board[next.getx()][next.gety()] = movingpiece;
			m_board[current.getx()][current.gety()] = nullptr;
		}
};

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
                if (i == 1)
			    	p_ptr->setColor(Color::Black);
                else
                    p_ptr->setColor(Color::White);
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

Board::~Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (m_board[i][j] != nullptr)
                delete m_board[i][j];
        }
    }
}
