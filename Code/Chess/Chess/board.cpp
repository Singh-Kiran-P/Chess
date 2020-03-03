#include "board.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "TermColor.hpp"

bool Board::checkWin() const {
	for (int i = 0; i < SIZE_BOARD; ++i) {
		if (m_board[0][i] != nullptr || m_board[7][i] != nullptr)
			return true; // triggers when a pawn has reached the opposite side
	}
	return false;
};

bool Board::move(Position current, Position next, Player* player) {
	Pawn* movingpiece = m_board[current.getx()][current.gety()];
	if (movingpiece == nullptr || movingpiece->getColor() != player->color()) { //pawn can only move to empty spaces or enemy spaces
		if (!(player->get_is_ai()))
			std::cout << termcolor::red << "Invalid move" << termcolor::white << std::endl;
		return false;
	}

	Pawn* nextpiece = m_board[next.getx()][next.gety()];
	if (movingpiece->moveRestrictions(current.getx(), current.gety(), next.getx(), next.gety(), movingpiece, nextpiece)) {
		movingpiece->increaseTurnCount();
		m_board[next.getx()][next.gety()] = movingpiece;
		m_board[current.getx()][current.gety()] = nullptr;
		if (nextpiece != nullptr)
			delete nextpiece;
		return true;
	}
	if (!(player->get_is_ai()))
		std::cout << termcolor::red << "Invalid move" << termcolor::white << std::endl;
	return false;
};

bool Board::move(std::string currentpos, std::string moveTo, Player* player)
{
	Position current;
	Position next;
	current.setpos(currentpos);
	next.setpos(moveTo);
	return Board::move(current, next,player);
};

bool Board::validChoice(int xpos, int ypos, Color playercolor)  {
	if (m_board[xpos][ypos] == nullptr)
		return false;

	else if ((m_board[xpos][ypos])->getColor() != playercolor)
		return false;

	if (playercolor == Color::Black) {
		if (m_board[xpos + 1][ypos] != nullptr) {
			if (m_board[xpos + 1][ypos - 1] != nullptr && 0 <= (ypos - 1) <= 8)
				return ((m_board[xpos][ypos])->getColor() != (m_board[xpos + 1][ypos - 1])->getColor());
			else if (m_board[xpos + 1][ypos + 1] != nullptr && 0 <= (ypos + 1) <= 8)
				return ((m_board[xpos][ypos])->getColor() != (m_board[xpos + 1][ypos + 1])->getColor());
		}
		return true;
	}

	else if (playercolor == Color::White) {
		if (m_board[xpos - 1][ypos] != nullptr) {
			if (m_board[xpos - 1][ypos - 1] != nullptr && 0 <= (ypos - 1) <= 8)
				return ((m_board[xpos][ypos])->getColor() != (m_board[xpos - 1][ypos - 1])->getColor());
			else if (m_board[xpos - 1][ypos + 1] != nullptr && 0 <= (ypos + 1) <= 8)
				return ((m_board[xpos][ypos])->getColor() != (m_board[xpos - 1][ypos + 1])->getColor());
		}
		return true;
	}
	return false;
};

void Board::AiMove(Player* player) {
	int curr_x;
	int curr_y;
	Position currpos;
	int next_x;
	int next_y;
	Position nextpos;
	bool valid_next_spot = false;

	do {
		curr_x = (rand() % SIZE_BOARD);
		curr_y = (rand() % SIZE_BOARD);
	} while (m_board[curr_x][curr_y] == nullptr || (m_board[curr_x][curr_y])->getColor() != player->color());
	currpos.setpos(SIZE_BOARD - curr_x, curr_y);

	do {
		do {
			if (player->color() == Color::Black) {
				if ((m_board[curr_x][curr_y])->turnCount() == 0)
					next_x = curr_x + ((rand() % 2) + 1);
				else
					next_x = curr_x + ((rand() % 1) + 1);
			}
			else {
				if ((m_board[curr_x][curr_y])->turnCount() == 0)
					next_x = curr_x - ((rand() % 2) + 1);
				else
					next_x = curr_x - ((rand() % 1) + 1);
			}

			next_y = curr_y + (rand() % 3) - 1;

		} while (m_board[next_x][next_y] != nullptr);
		nextpos.setpos(SIZE_BOARD - next_x, next_y);

	} while(move(currpos, nextpos, player) == false);

};

bool Piece::noBlockers(Piece* movingpiece, Position current, Position next) {
    int curr_x = current.getx();
    int curr_y = current.gety();
    int next_x = next.getx();
    int next_y = next.gety();

    if (movingpiece->getColor()) == Color::White) {
		if (curr_x >= next_x) {
        	while (curr_x > next_x)
		}
    }
}

void Board::printBoard() const {
	std::cout << termcolor::green << "   _______________" << std::endl;
	for (int i = 0; i < SIZE_BOARD; i++) {
		std::cout << termcolor::green << SIZE_BOARD - i << " |" << termcolor::white; //Board is zero-indexed, while the chess game is flipped and has 1 at the bottom
		for (int j = 0; j < SIZE_BOARD; j++) {
			if (m_board[i][j] != nullptr) {
				Pawn* temp_pawn = m_board[i][j];

				if (temp_pawn->getColor() == Color::Black) {
					std::cout << termcolor::blue;
				}

				if (j < SIZE_BOARD-1) {
					std::cout << temp_pawn->getId() << ' ';
				}
				else {
					std::cout << temp_pawn->getId();
				}
				std::cout << termcolor::white;
			}
			else if (j < SIZE_BOARD-1) {
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

Board::Board() {
	for (int i = 0; i < SIZE_BOARD; i++) {
		for (int j = 0; j < SIZE_BOARD; j++) {
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
	for (int i = 0; i < SIZE_BOARD; i++) {
		for (int j = 0; j < SIZE_BOARD; j++) {
			if (m_board[i][j] != nullptr)
				delete m_board[i][j];
		}
	}
};
