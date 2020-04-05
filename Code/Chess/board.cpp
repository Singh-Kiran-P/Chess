#include "board.h"

void Board::changePawn(QString type, Pawn *p)
{
    QPoint posP = p->getPos();
    if (type == "Queen")
        m_board[posP.x()][posP.y()] = new Queen{p->getColor(), posP};
    else if (type == "Rook")
            m_board[posP.x()][posP.y()] = new Rook{p->getColor(), posP};
    else if (type == "Knight")
            m_board[posP.x()][posP.y()] = new Knight{p->getColor(), posP};
    else if (type == "Bishop")
            m_board[posP.x()][posP.y()] = new Bishop{p->getColor(), posP};

    delete p;
};

Pawn* Board::checkPromotions() {
    for (int row = 0; row < SIZE_BOARD; row++) {
        if (m_board[row][0] != nullptr && m_board[row][0]->getId() == 'P')
            return static_cast<Pawn*>(m_board[row][0]);
        else if (m_board[row][SIZE_BOARD - 1] != nullptr && m_board[row][SIZE_BOARD - 1]->getId() == 'P')
            return static_cast<Pawn*>(m_board[row][SIZE_BOARD - 1]);
    }
    return nullptr;
}

bool Board::SafePos(const Piece *movingpiece,const QPoint &next)
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

Piece* Board::checkedKing() {
    for (auto KingColor : {Qt::white, Qt::black}) {
        Piece* King = FindKing(KingColor);
        if (!SafePos(King, King->getPos()))
            return King;
    }
    return nullptr;
}

void Board::move(QPoint current, QPoint next, bool realMove)
{
    Piece *movingpiece = getPiece(current);
    Piece *nextpiece = getPiece(next);

    m_board[next.x()][next.y()] = movingpiece;
    m_board[current.x()][current.y()] = nullptr;
	movingpiece->setPos(next);
    if (realMove) {
        delete nextpiece;
        emit moved(current * 100, next * 100);

        if (auto pawn = dynamic_cast<Pawn *>(movingpiece))
            pawn->increaseTurnCount();
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

bool Board::noBlockers(const QPoint &current, const QPoint &next) const
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

Piece *Board::getPiece(const QPoint &p) const
{
    return m_board[p.x()][p.y()];
};

void Board::placePieces()
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
                p_ptr = new Pawn{PieceColor, tempPos};
                m_board[x][y] = p_ptr;
                emit placedPiece(p_ptr);
			}
            else if (y == 0 || y == 7)
			{
                if (x == 0 || x == 7) // Rooks
                    p_ptr = new Rook{PieceColor, tempPos};
                else if (x == 1 || x == 6) //Knight
                    p_ptr = new Knight{PieceColor, tempPos};
                else if (x == 2 || x == 5) //Bishop
                    p_ptr = new Bishop{PieceColor, tempPos};
                else if (x == 3) //Queen
                    p_ptr = new Queen{PieceColor, tempPos};
                else if (x == 4) //King
                    p_ptr = new King{PieceColor, tempPos};
                m_board[x][y] = p_ptr;
                emit placedPiece(p_ptr);
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
