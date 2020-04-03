#include "board.h"

void Board::changePawn(Pawn *p)
{
    QPoint posP = p->getPos();

	if (p->getColor() == Qt::black)
	{
        m_board[posP.x()][posP.y()] = new Queen('Q', Qt::black, posP);
	}
	else
	{
        m_board[posP.x()][posP.y()] = new Queen('Q', Qt::white, posP);
	}
	delete p;
};

bool Board::SafePos(Piece *movingpiece, QPoint next)
{
    for (int y = 0; y < SIZE_BOARD; y++)
	{
        for (int x = 0; x < SIZE_BOARD; x++)
		{
            if (m_board[x][y] != nullptr && m_board[x][y]->getColor() != movingpiece->getColor())
			{
                if (m_board[x][y]->moveRestrictions(movingpiece, next))
				{ //Checks if any enenmy piece can take the king's next position
                    if (m_board[x][y]->getId() != 'N')
					{
                        if (noBlockers(m_board[x][y]->getPos(), next))
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

Piece* Board::FindKing(QColor color)
{
    for (int y = 0; y < SIZE_BOARD; y++)
    {
        for (int x = 0; x < SIZE_BOARD; x++)
        {
            if (m_board[x][y] != nullptr && m_board[x][y]->getId() == 'K')
			{
                if (m_board[x][y]->getColor() == color)
                    return m_board[x][y];
			}
		}
	}
	return nullptr;
};

void Board::move(QPoint current, QPoint next, bool realMove)
{
    Piece *movingpiece = getPiece(current);
    Piece *nextpiece = getPiece(next);

    m_board[next.x()][next.y()] = movingpiece;
    m_board[current.x()][current.y()] = nullptr;
	movingpiece->setPos(next);
	if (realMove)
	{
        if (auto pawn = dynamic_cast<Pawn *>(movingpiece))
			pawn->increaseTurnCount();
        delete nextpiece;
        emit moved(current * 100, next * 100);

	}
};

bool Board::Validmove(QPoint current, QPoint next, QColor playercolor)
{
    Piece *movingpiece = getPiece(current);
    Piece *nextpiece = getPiece(next);

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
        m_board[next.x()][next.y()] = nextpiece;
		return safeKing;
	}
	else
		return false;
};

bool Board::noBlockers(QPoint current, QPoint next) const
{ // Checks every position between current and next for pieces
    int curr_x{current.x()};
    int curr_y{current.y()};
    int next_x{next.x()};
    int next_y{next.y()};

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

Piece *Board::getPiece(QPoint p)
{
    return m_board[p.x()][p.y()];
};

Board::Board()
{
	QColor PieceColor{};
    QPoint tempPos{};
	Piece *p_ptr{};

    for (int y = 0; y < SIZE_BOARD; y++)
	{
        for (int x = 0; x < SIZE_BOARD; x++)
		{  
            tempPos.setX(x);
            tempPos.setY(y);
            if (y <= 1)
				PieceColor = Qt::black; // top of board is black
            else if (y >= 6)
				PieceColor = Qt::white; // bottom of board is white
            if (y == 1 || y == 6)
			{
				p_ptr = new Pawn{'P', PieceColor, tempPos};
                m_board[x][y] = p_ptr;
			}
            else if (y == 0 || y == 7)
			{
                if (x == 0 || x == 7) // Rooks
					p_ptr = new Rook{'R', PieceColor, tempPos};
                else if (x == 1 || x == 6) //Knight
					p_ptr = new Knight{'N', PieceColor, tempPos};
                else if (x == 2 || x == 5) //Bishop
					p_ptr = new Bishop{'B', PieceColor, tempPos};
                else if (x == 3) //Queen
					p_ptr = new Queen{'Q', PieceColor, tempPos};
                else if (x == 4) //King
					p_ptr = new King{'K', PieceColor, tempPos};
                m_board[x][y] = p_ptr;
			}
			else
                m_board[x][y] = nullptr;
		}
	}
};

Board::~Board()
{
    for (int y = 0; y < SIZE_BOARD; y++)
	{
        for (int x = 0; x < SIZE_BOARD; x++)
		{
            delete m_board[x][y];
		}
	}
};
