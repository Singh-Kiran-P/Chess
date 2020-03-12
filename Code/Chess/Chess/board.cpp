#include "board.h"

void Board::changePawn(Pawn* p)
{

	Position posP = p->getPos();

	if (p->getColor() == Color::Black)
	{
		delete p;

		m_board[posP.getx()][posP.gety()] = new Queen('Q', Color::Black, posP);

	}
	else
	{
		delete p;

		m_board[posP.getx()][posP.gety()] = new Queen('Q', Color::White, posP);

	}

}

bool Board::checkWin() {

	Piece* WhiteKing{ FindKing(Color::White) };
	Piece* BlackKing{ FindKing(Color::Black) };

	if (WhiteKing == nullptr || BlackKing == nullptr)
		return true;

	Piece* CheckedKing{ nullptr };
	if (!SafePos(WhiteKing, WhiteKing->getPos())) {
		CheckedKing = WhiteKing;
		cout << termcolor::red << "Check White King\n" << termcolor::reset << endl;
	}
	else if (!SafePos(BlackKing, BlackKing->getPos())) {
		CheckedKing = BlackKing;
		cout <<termcolor::red<< "Check Black King\n" << termcolor::reset<< endl;
	}

	if (CheckedKing == nullptr)
		return false;

	else {
		int curr_x = (CheckedKing->getPos()).getx();
		int curr_y = (CheckedKing->getPos()).gety();
		Position PossibleMove{};

		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if ((i != 0 || j != 0) && 0 <= curr_x + i && curr_x + i < SIZE_BOARD && 0 <= curr_y + j && curr_y + j < SIZE_BOARD) {
					PossibleMove.setpos(curr_x + i, curr_y + j);
						if (SafePos(CheckedKing, PossibleMove)) { // Checks if king can move out of check
						if ((m_board[curr_x + i][curr_y + j] == nullptr || m_board[curr_x + i][curr_y + j]->getColor() != CheckedKing->getColor()))
							return false;
					}
				}
			}
		}
		cout << termcolor::red << "Checkmate\n" << termcolor::reset << endl;
		return true;
	}
};

bool Board::SafePos(Piece* movingpiece, Position next) {
	for (int i = 0; i < SIZE_BOARD; i++) {
		for (int j = 0; j < SIZE_BOARD; j++) {
			if (m_board[i][j] != nullptr && m_board[i][j]->getColor() != movingpiece->getColor()) {
				if (m_board[i][j]->moveRestrictions(movingpiece, next) && noBlockers(m_board[i][j]->getPos(), next)) //Checks if any enenmy piece can take the king's next position
					return false;
			}
		}
	}
	return true;
};

Piece* Board::FindKing(Color color) {
	for (int i = 0; i < SIZE_BOARD; i++) {
		for (int j = 0; j < SIZE_BOARD; j++) {
			if (m_board[i][j] != nullptr && m_board[i][j]->getId() == 'K') {
				if (m_board[i][j]->getColor() == color)
					return m_board[i][j];
			}
		}
	}
	return nullptr;
};

bool Board::move(Position current, Position next, Player* player) {
	Piece* movingpiece = m_board[current.getx()][current.gety()];
	Piece* nextpiece = m_board[next.getx()][next.gety()];

	if (movingpiece == nullptr || movingpiece->getColor() != player->color()) // A piece must be selected to move it
		return false;

	bool PossibleWalk{ true };
	if (movingpiece->getId() != 'N')
		PossibleWalk = noBlockers(current, next);

	if (PossibleWalk && movingpiece->moveRestrictions(nextpiece, next)) {
		m_board[next.getx()][next.gety()] = movingpiece;
		m_board[current.getx()][current.gety()] = nullptr;
		movingpiece->setPos(next);

		Piece* TeamKing = FindKing(movingpiece->getColor());
		if (TeamKing == nullptr || !SafePos(TeamKing, TeamKing->getPos())) { // A move that puts the king in check is illegal
			m_board[current.getx()][current.gety()] = movingpiece;
			m_board[next.getx()][next.gety()] = nextpiece;
			movingpiece->setPos(current);
			return false;
		}
		else {
			if (auto* i = dynamic_cast<Pawn*>(movingpiece))
				i->increaseTurnCount();

			if (nextpiece != nullptr)
				delete nextpiece;
			if (auto* i = dynamic_cast<Pawn*>(movingpiece))
			{
				if (i->getPos().getx() == SIZE_BOARD - 1 || i->getPos().getx() == 0)
					changePawn(i);
			}
			return true;
		}
	}

	return false;
}


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

Piece* Board::getPiece(Position p) {
	return m_board[p.getx()][p.gety()];
}

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

			if (i == 1 || i == 6) {
				p_ptr = new Pawn{ 'P', PieceColor, tempPos };
				m_board[i][j] = p_ptr;
			}
			else if (i == 0 || i == 7) {

				if (j == 0 || j == 7) // Rooks
					p_ptr = new Rook{ 'R', PieceColor, tempPos };
				else if (j == 1 || j == 6) //Knight
					p_ptr = new Knight{ 'N', PieceColor, tempPos };
				else if (j == 2 || j == 5) //Bishop
					p_ptr = new Bishop{ 'B', PieceColor, tempPos };
				else if (j == 3) //Queen
					p_ptr = new Queen{ 'Q', PieceColor, tempPos };
				else if (j == 4) //King
					p_ptr = new King{ 'K', PieceColor, tempPos };
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
