#include "queen.h"

bool Queen::moveRestrictions(Piece *nextpiece, QPoint nextPos)
{

    int curr_x = m_position.x();
    int curr_y = m_position.y();

    int next_x = nextPos.x();
    int next_y = nextPos.y();

	if (curr_x == next_x && curr_y == next_y)
		return false;

	if (nextpiece != nullptr)
	{
		if (nextpiece->getColor() == m_color)
			return false;
	}

	if (abs(next_x - curr_x) == abs(next_y - curr_y) || (curr_y == next_y) || (curr_x == next_x))
		return true;
	else
		return false;
};

Queen::Queen(char id, QColor color, QPoint Pos) : Piece(id, color, Pos){};
