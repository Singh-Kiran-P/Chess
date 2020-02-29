#include "board.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "TermColor.hpp"

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
                m_board[next_x][next_y] = nullptr;
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
                m_board[next_x][next_y] = nullptr;
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

bool Board::checkWin() {
	for (int i = 0; i < 8; ++i) {
		if (m_board[0][i] != nullptr || m_board[7][i] != nullptr)
			return true; // triggers when a pawn has reached the opposite side
	}
	return false;
};

bool Board::move(std::string currentpos, std::string moveTo, Player* player) {
	Position current;
	Position next;
	current.setpos(currentpos);
	next.setpos(moveTo);

	Pawn* movingpiece = getPiece(current.getx(), current.gety());
	if (movingpiece == nullptr || movingpiece->getColor() != player->color()) { //pawn can only move to empty spaces or enemy spaces
		std::cout << termcolor::red << "Invalid move" << termcolor::white << std::endl;
		return false;
	}

	Pawn* nextpiece = getPiece(next.getx(), next.gety());
	if (checkRestrictions(current.getx(), current.gety(), next.getx(), next.gety(), movingpiece, nextpiece)) {
		if (movingpiece->firstTurn())
			movingpiece->setfirstTurnFalse();
		m_board[next.getx()][next.gety()] = movingpiece;
		m_board[current.getx()][current.gety()] = nullptr;

		return true;
	}

	std::cout << termcolor::red << "Invalid move" << termcolor::white << std::endl;
	return false;
};

void Board::AiMove(Player* player) {
	int curr_x;
	int curr_y;
	std::string currpos;
	int next_x;
	int next_y;
	std::string nextpos;

	do {
		curr_x = (rand() % 8) + 1;
		curr_y = (rand() % 8) + 1;
	} while (m_board[curr_x][curr_y] == nullptr && (m_board[curr_x][curr_y])->getColor() != player->color());

	do {
		do {
			next_x = (rand() % 8) + 1;
			next_y = (rand() % 8) + 1;
		} while (m_board[next_x][next_y] == nullptr);

	} while(move(curr_x, curr_y, next_x, next_y, player) == false);

};

void Board::printBoard() {
	std::cout << termcolor::green << "   _______________" << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << termcolor::green << 8 - i << " |" << termcolor::white; //Board is zero-indexed, while the chess game is flipped and has 1 at the bottom
		for (int j = 0; j < 8; j++) {
			if (m_board[i][j] != nullptr) {
				Pawn* temp_pawn = m_board[i][j];

				if (temp_pawn->getColor() == Color::Black) {
					std::cout << termcolor::blue;
				}

				if (j < 7) {
					std::cout << temp_pawn->getId() << ' ';
				}
				else {
					std::cout << temp_pawn->getId();
				}
				std::cout << termcolor::white;
			}
			else if (j < 7) {
				std::cout << ". ";
			}
			else {
				std::cout << ".";
			}
		}

		std::cout << termcolor::green << '|';
		std::cout << '\n';
	}

	std::cout << termcolor::green << "   _______________" << std::endl;
	std::cout <<  "   A B C D E F G H" << termcolor::white << std::endl;


};

Pawn* Board::getPiece(int x, int y) {
	return m_board[x][y];
};

Board::Board() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == 1 || i == 6) {
				Pawn* p_ptr{ new Pawn{} };
				m_board[i][j] = p_ptr;
				p_ptr->setId('P');
				if (i == 1)
					p_ptr->setColor(Color::Black); // top of board is black
				else
					p_ptr->setColor(Color::White); // bottom of board is white
			}
			else
				m_board[i][j] = nullptr;
		}
	}
};

Board::~Board() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (m_board[i][j] != nullptr)
				delete m_board[i][j];
		}
	}
};
