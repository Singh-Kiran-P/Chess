#include "board.h"

bool Board::checkWin() const {
	//for (int i = 0; i < SIZE_BOARD; ++i) {
	//	if (m_board[0][i] != nullptr || m_board[7][i] != nullptr)
	//		return true; // triggers when a pawn has reached the opposite side
	//}
	return false;
};

bool Board::move(Position current, Position next, Player* player) {
	Piece* movingpiece = m_board[current.getx()][current.gety()];
	if (movingpiece == nullptr) { // A piece must be selected to move it
		if (auto* playertype = dynamic_cast<HumanPlayer*>(player)) // Only print this error message when a player causes it
			std::cout << termcolor::red << "Invalid move" << termcolor::white << std::endl;
		return false;
	}

	bool PossibleWalk{ true };
	if (movingpiece->Id() != 'N')
		PossibleWalk = noBlockers(current, next);

	Piece* nextpiece = m_board[next.getx()][next.gety()];
	if (movingpiece->moveRestrictions(nextpiece, next, player->color()) && PossibleWalk) {
		if (auto* i = dynamic_cast<Pawn*>(movingpiece))
			i->increaseTurnCount();
		m_board[next.getx()][next.gety()] = movingpiece;
		movingpiece->setPos(next);
		m_board[current.getx()][current.gety()] = nullptr;
		if (nextpiece != nullptr)
			delete nextpiece;
		return true;
	}

	if (auto* playertype = dynamic_cast<HumanPlayer*>(player))
		std::cout << termcolor::red << "Invalid move" << termcolor::white << std::endl;
	return false;
};

bool Board::noBlockers(Position current, Position next) const {
	int curr_x{ current.getx() };
	int curr_y{ current.gety() };
	int next_x{ next.getx() };
	int next_y{ next.gety() };

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

				if (m_board[i][j]->getColor() == Color::Black)
					std::cout << termcolor::blue;
				std::cout << m_board[i][j]->Id();
				std::cout << termcolor::white;

				if (j < SIZE_BOARD - 1)
					std::cout << " ";
			}
			else {
				std::cout << ".";
				if (j < SIZE_BOARD - 1)
					std::cout << " ";
			}
		}
		std::cout << termcolor::green << '|';
		std::cout << '\n';
	}
	std::cout << termcolor::green << "   _______________" << std::endl;
	std::cout << "   A B C D E F G H" << termcolor::white << std::endl;

};

Piece* Board::getPiece(Position p) {
	return m_board[p.getx()][p.gety()];
};

Board::Board() {
	Color PieceColor{};
	Position tempPos{};
	Piece* p_ptr{};

	for (int i = 0; i < SIZE_BOARD; i++) {
		for (int j = 0; j < SIZE_BOARD; j++) {

			if (i <= 1) {
				tempPos.setpos(i, j);
				PieceColor = Color::Black; // top of board is black
			}
			else if (i >= 6) {
				tempPos.setpos(i, j);
				PieceColor = Color::White; // bottom of board is white
			}

			if ( i == 1 || i == 6) {
				p_ptr = new Pawn{'P', PieceColor, tempPos};
				m_board[i][j] = p_ptr;
			}
			else if (i == 0 || i == 7) {

				if (j == 0 || j == 7) // Rooks
					p_ptr = new Rook{'R', PieceColor, tempPos};
				else if (j == 1 || j == 6) //Knight
					p_ptr = new Knight{'N', PieceColor, tempPos};
				else if (j == 2 || j == 5) //Bishop
					p_ptr = new Bishop{'B', PieceColor, tempPos};
				else if (j == 3) //Queen
					p_ptr = new Queen{'Q', PieceColor, tempPos};
				else if (j == 4) //King
					p_ptr = new King{'K', PieceColor, tempPos};
				m_board[i][j] = p_ptr;
			}
			else
				m_board[i][j] = nullptr;
		}
	}
};

Board::~Board() {
	for (int i = 0; i < SIZE_BOARD; i++) {
		for (int j = 0; j < SIZE_BOARD; j++) {
			delete m_board[i][j];
		}
	}
};
