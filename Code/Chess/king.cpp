#include "king.h"

bool King::moveRestrictions(Piece *nextpiece, QPoint nextPos)
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

	if (abs(next_x - curr_x) <= 1 && abs(next_y - curr_y) <= 1)
		return true;
	else
		return false;
};

King::King(char id, QColor color, QPoint Pos) : Piece(id, color, Pos){};
