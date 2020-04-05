#include "rook.h"

bool Rook::moveRestrictions(const Piece *nextpiece, const QPoint &nextPos)
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

	if ((curr_x == next_x) || (curr_y == next_y))
		return true;
	else
		return false;
};

Rook::Rook(QColor color, QPoint Pos) : Piece('R', color, Pos){};
