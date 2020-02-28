#include "board.h"
#include <iostream>
#include "TermColor.hpp"
#include <stdlib.h>
Pawn* Board::getPiece(Position position) {
	int x = position.getx();
	int y = position.gety();

	return m_board[x][y];
};

bool Board::checkRestrictions(int curr_x, int curr_y, int next_x, int next_y, Pawn* movingpiece, Pawn* nextpiece) {
	if (movingpiece->getColor() == Color::White) {
        int max_delta_x = -1;
        if (movingpiece->firstTurn())
            max_delta_x--;

        if (curr_y == next_y && (max_delta_x <= (next_x - curr_x) && (next_x - curr_x) < 0)) {
            if (nextpiece == nullptr)
                return true;
            else {
                return false;
            }
        }
        else if (abs(curr_y - next_y) == 1 && (next_x - curr_x) == -1) {
            if (movingpiece->getColor() != nextpiece->getColor()) {
                m_board[curr_y][curr_x] = nullptr;
                delete nextpiece;
                return true;
            }
            else {
                return false;
            }
        }
    }

    else if (movingpiece->getColor() == Color::Black) {
        int max_delta_x = 1;
        if (movingpiece->firstTurn())
            max_delta_x++;

            if (curr_y == next_y && (0 < (next_x - curr_x) && (next_x - curr_x) <= max_delta_x)) {
                if (nextpiece == nullptr)
                    return true;
                else {
                    return false;
                }
            }
        else if (abs(curr_y - next_y) == 1 && (next_x - curr_x) == 1) {
            if (movingpiece->getColor() != nextpiece->getColor()) {
                m_board[curr_y][curr_x] = nullptr;
                delete nextpiece;
                return true;
            }
            else {
                return false;
            }
        }
    }
	return false;
};

bool Board::move(std::string currentpos, std::string moveTo,Color playerColor) {
	Position current;
	Position next;
	current.setpos(currentpos);
	next.setpos(moveTo);

    Pawn* movingpiece = getPiece(current.getx(), current.gety());
    if (movingpiece == nullptr || movingpiece->getColor() != playerColor) {
		std::cout << termcolor::red << "Invalid move" << termcolor::white << std::endl;
        return false;
	}

	Pawn* nextpiece = getPiece(next.getx(), next.gety());
	if (checkRestrictions(current.getx(), current.gety(), next.getx(), next.gety(), movingpiece, nextpiece)) {
        if (movingpiece->firstTurn())
            movingpiece->setfirstTurnFalse();
		m_board[next.getx()][next.gety()] = movingpiece;
		m_board[current.getx()][current.gety()] = nullptr;
        system("CLS");
		return true;
	}
	std::cout << termcolor::red << "Invalid move" << termcolor::white << std::endl;
	return false;
};

void Board::printBoard() {
    std::cout << "   A B C D E F G H" << termcolor::white << std::endl;
    std::cout << termcolor::green << "   _______________" << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << termcolor::green << i + 1 << " |" << termcolor::white;
		for (int j = 0; j < 8; j++) {
			if (m_board[i][j] != nullptr) {
				Pawn* temp_pawn = m_board[i][j];
                                      
				if (temp_pawn->getColor() == Color::Black) {
					std::cout << termcolor::blue;
				}

                if (j<7)
                {
                    std::cout << temp_pawn->getId() << ' ';

                }
                else {
                    std::cout << temp_pawn->getId();

                }
				std::cout << termcolor::white;        
            }
            else if(j<7) {
                std::cout << ". ";
            }
            else {
                std::cout << ".";

            }

		}

            std::cout << termcolor::green << '|';

    
		std::cout << '\n';
   

	}

    std::cout << termcolor::green << "   _______________" << termcolor::white<< std::endl;


};

Pawn* Board::getPiece(int x, int y) {
	return m_board[x][y];
}

Board::Board() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == 1 || i == 6) {
				Pawn* p_ptr{ new Pawn{} };
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

Board::~Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (m_board[i][j] != nullptr) {
                delete m_board[i][j]; // TODO: fix double denconstructor call
            }
        }
    }
};
