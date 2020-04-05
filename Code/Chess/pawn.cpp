#include "pawn.h"

int Pawn::turnCount() const
{
	return m_turnCount;
};

void Pawn::increaseTurnCount()
{
	m_turnCount++;
};

bool Pawn::moveRestrictions(const Piece *nextpiece, const QPoint &nextPos)
{

    int curr_x = m_position.x();
    int curr_y = m_position.y();

    int next_x = nextPos.x();
    int next_y = nextPos.y();

	if (curr_x == next_x && curr_y == next_y)
		return false;

    int max_delta_y{1};
	if (m_color == Qt::white)
	{
        if (next_y >= curr_y)
			return false;
	}

	else if (m_color == Qt::black)
	{
        if (next_y <= curr_y)
			return false;
	}

	if (m_turnCount == 0)
        max_delta_y = 2;

    if (curr_x == next_x && abs(next_y - curr_y) <= max_delta_y)
	{
		if (nextpiece == nullptr)
			return true;
		else
			return false;
	}
    else if (abs(curr_x - next_x) == 1 && abs(next_y - curr_y) == 1)
	{
		if (nextpiece != nullptr)
		{
			if (m_color != nextpiece->getColor())
				return true;
			else
				return false;
		}
		else
			return false;
	}
	return false;
};

Pawn::Pawn(QColor color, QPoint Pos) : Piece('P', color, Pos){};
