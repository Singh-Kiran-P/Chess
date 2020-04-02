#include "board.h"

void Board::changePawn(Pawn *p)
{
	Position posP = p->getPos();

	if (p->getColor() == Qt::black)
	{
		m_board[posP.getx()][posP.gety()] = new Queen('Q', Qt::black, posP);
	}
	else
	{
		m_board[posP.getx()][posP.gety()] = new Queen('Q', Qt::white, posP);
	}
	delete p;
};

bool Board::SafePos(Piece *movingpiece, Position next)
{
	for (int i = 0; i < SIZE_BOARD; i++)
	{
		for (int j = 0; j < SIZE_BOARD; j++)
		{
			if (m_board[i][j] != nullptr && m_board[i][j]->getColor() != movingpiece->getColor())
			{
				if (m_board[i][j]->moveRestrictions(movingpiece, next))
				{ //Checks if any enenmy piece can take the king's next position
					if (m_board[i][j]->getId() != 'N')
					{
						if (noBlockers(m_board[i][j]->getPos(), next))
							return false;
					}
					else
						return false;
				}
			}
		}
	}
	return true;
};

Piece *Board::FindKing(QColor color)
{
	for (int i = 0; i < SIZE_BOARD; i++)
	{
		for (int j = 0; j < SIZE_BOARD; j++)
		{
			if (m_board[i][j] != nullptr && m_board[i][j]->getId() == 'K')
			{
				if (m_board[i][j]->getColor() == color)
					return m_board[i][j];
			}
		}
	}
	return nullptr;
};

void Board::move(Position current, Position next, bool realMove)
{
	Piece *movingpiece = m_board[current.getx()][current.gety()];

	m_board[next.getx()][next.gety()] = movingpiece;
	m_board[current.getx()][current.gety()] = nullptr;
	movingpiece->setPos(next);
	if (realMove)
	{
		if (auto pawn = dynamic_cast<Pawn *>(movingpiece))
			pawn->increaseTurnCount();
	}
};

bool Board::Validmove(Position current, Position next, QColor playercolor)
{
	Piece *movingpiece = m_board[current.getx()][current.gety()];
	Piece *nextpiece = m_board[next.getx()][next.gety()];

	if (movingpiece == nullptr || movingpiece->getColor() != playercolor) // A valid piece must be selected to move it
		return false;

	if (nextpiece != nullptr && nextpiece->getColor() == movingpiece->getColor())
		return false;

	bool PossibleWalk{true};
	if (movingpiece->getId() != 'N') // Only knights can ignore blockers
		PossibleWalk = noBlockers(current, next);

	if (PossibleWalk && movingpiece->moveRestrictions(nextpiece, next))
	{
		move(current, next);

		bool safeKing;
		Piece *TeamKing = FindKing(movingpiece->getColor());
		if (TeamKing == nullptr || !SafePos(TeamKing, TeamKing->getPos())) // A move that puts the king in check is illegal
			safeKing = false;
		else
			safeKing = true;

		move(next, current);
		m_board[next.getx()][next.gety()] = nextpiece;
		return safeKing;
	}
	else
		return false;
};

bool Board::noBlockers(Position current, Position next) const
{ // Checks every position between current and next for pieces
	int curr_x{current.getx()};
	int curr_y{current.gety()};
	int next_x{next.getx()};
	int next_y{next.gety()};

	while (curr_x != next_x || curr_y != next_y)
	{
		if (next_x < curr_x)
			next_x++;
		else if (next_x > curr_x)
			next_x--;
		if (next_y < curr_y)
			next_y++;
		else if (next_y > curr_y)
			next_y--;
		if (next_x != curr_x || next_y != curr_y)
		{
			if (m_board[next_x][next_y] != nullptr)
				return false;
		}
	}
	return true;
};

Piece *Board::getPiece(Position p)
{
	return m_board[p.getx()][p.gety()];
};

Board::Board()
{
	QColor PieceColor{};
	Position tempPos{};
	Piece *p_ptr{};

	for (int i = 0; i < SIZE_BOARD; i++)
	{
		for (int j = 0; j < SIZE_BOARD; j++)
		{

			if (i <= 1)
			{
				tempPos.setpos(i, j);
				PieceColor = Qt::black; // top of board is black
			}
			else if (i >= 6)
			{
				tempPos.setpos(i, j);
				PieceColor = Qt::white; // bottom of board is white
			}
			if (i == 1 || i == 6)
			{
				p_ptr = new Pawn{'P', PieceColor, tempPos};
				m_board[i][j] = p_ptr;
			}
			else if (i == 0 || i == 7)
			{
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

Board::~Board()
{
	for (int i = 0; i < SIZE_BOARD; i++)
	{
		for (int j = 0; j < SIZE_BOARD; j++)
		{
			delete m_board[i][j];
		}
	}
};
