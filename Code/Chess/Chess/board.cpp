#include "board.h"
#include "TermColor.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

bool Board::checkWin() const {
	for (int i = 0; i < SIZE_BOARD; ++i) {
		if (m_board[0][i] != nullptr || m_board[7][i] != nullptr)
			return true; // triggers when a pawn has reached the opposite side
	}
	return false;
};

bool Board::move(Position current, Position next, Player* player) {
	Piece* movingpiece = m_board[current.getx()][current.gety()];
	if (movingpiece == nullptr || movingpiece->getColor() != player->color()) { //Piece can only move to empty spaces or enemy spaces
		if (!(player->get_is_ai()))
			std::cout << termcolor::red << "Invalid move" << termcolor::white << std::endl;
		return false;
	}

	Piece* nextpiece = m_board[next.getx()][next.gety()];
	if (movingpiece->moveRestrictions(movingpiece, nextpiece, next.getx(), next.gety()) && noBlockers(current, next)) {
		if (auto *i = dynamic_cast<Pawn*>(movingpiece))
			i->increaseTurnCount();
		m_board[next.getx()][next.gety()] = movingpiece;
		movingpiece->setPos(next);
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
	Position current{currentpos};
	Position next{moveTo};
	return Board::move(current, next,player);
};

bool Board::validChoice(int xpos, int ypos, Color playercolor)  {
	if (m_board[xpos][ypos] == nullptr)
		return false;

	else if ((m_board[xpos][ypos])->getColor() != playercolor)
		return false;

	if (playercolor == Color::Black) {
		if (m_board[xpos + 1][ypos] != nullptr) {
			if (m_board[xpos + 1][ypos - 1] != nullptr && 0 <= (ypos - 1) < 8)
				return ((m_board[xpos][ypos])->getColor() != (m_board[xpos + 1][ypos - 1])->getColor());
			else if (m_board[xpos + 1][ypos + 1] != nullptr && 0 <= (ypos + 1) < 8)
				return ((m_board[xpos][ypos])->getColor() != (m_board[xpos + 1][ypos + 1])->getColor());
			else
				return false;
		}
		else
			return true;
	}

	else if (playercolor == Color::White) {
		if (m_board[xpos - 1][ypos] != nullptr) {
			if (m_board[xpos - 1][ypos - 1] != nullptr && 0 <= (ypos - 1) < 8)
				return ((m_board[xpos][ypos])->getColor() != (m_board[xpos - 1][ypos - 1])->getColor());
			else if (m_board[xpos - 1][ypos + 1] != nullptr && 0 <= (ypos + 1) < 8)
				return ((m_board[xpos][ypos])->getColor() != (m_board[xpos - 1][ypos + 1])->getColor());
			else
				return false;
		}
		else
			return true;
	}
	return false;
};

void Board::AiMove(Player* player) {
	int curr_x{};
	int curr_y{};
	int next_x{};
	int next_y{};
	bool valid_next_spot{ false };
	Position nextpos{};

	do {
		curr_x = (rand() % SIZE_BOARD);
		curr_y = (rand() % SIZE_BOARD);
	} while (!validChoice(curr_x, curr_y, player->color()));
	Position currpos{curr_x, curr_y};

	do {
		do {
			if (player->color() == Color::Black) {
				if (auto *i = dynamic_cast<Pawn*> (m_board[curr_x][curr_y])) {
					if (i->turnCount() == 0)
						next_x = curr_x + ((rand() % 2) + 1);
					else
						next_x = curr_x + ((rand() % 1) + 1);
				}
			}
			else {
				if (auto *i = dynamic_cast<Pawn*> (m_board[curr_x][curr_y])) {
					if (i->turnCount() == 0)
						next_x = curr_x - ((rand() % 2) + 1);
					else
						next_x = curr_x - ((rand() % 1) + 1);
			}
		}

			next_y = curr_y + (rand() % 3) - 1;
			if (m_board[next_x][next_y] != nullptr) {
				if (m_board[next_x][next_y]->getColor() != player->color())
					valid_next_spot = true;
			}
			else {
				valid_next_spot = true;
			}

		} while (!valid_next_spot);
		nextpos.setpos((SIZE_BOARD - next_x), next_y);

	} while(move(currpos, nextpos, player) == false);

};

bool Board::noBlockers(Position current, Position next) const {
    int curr_x{current.getx()};
    int curr_y{current.gety()};
    int next_x{next.getx()};
    int next_y{next.gety()};

	while (curr_x != next_x || curr_y != next_y) {
		if (next_x < curr_x)
			next_x++;
		else if (next_x > curr_x)
			next_x--;
		if (next_y < curr_y)
			next_y++;
		else if (next_y > curr_y)
			next_y--;
		if (next_x != curr_x || next_y != curr_y) {
			if (m_board[next_x][next_y] != nullptr)
				return false;
		}
	}
	return true;

};

void Board::printBoard() const {
	std::cout << termcolor::green << "   _______________" << std::endl;
	for (int i = 0; i < SIZE_BOARD; i++) {
		std::cout << termcolor::green << SIZE_BOARD - i << " |" << termcolor::white; //Board is zero-indexed, while the chess game is flipped and has 1 at the bottom
		for (int j = 0; j < SIZE_BOARD; j++) {
			if (m_board[i][j] != nullptr) {

				if (m_board[i][j]->getColor() == Color::Black) {
					std::cout << termcolor::blue;
				}

				if (j < SIZE_BOARD-1) {
					std::cout << m_board[i][j]->getId() << ' ';
				}
				else {
					std::cout << m_board[i][j]->getId();
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
	for (int i{0}; i < SIZE_BOARD; i++) {
		for (int j{0}; j < SIZE_BOARD; j++) {
			if (i == 1 || i == 6) {
				Pawn* p_ptr{ new Pawn };
				m_board[i][j] = p_ptr;
				p_ptr->setId('P');
				Position tempPos{i, j};
				p_ptr->setPos(tempPos);
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
