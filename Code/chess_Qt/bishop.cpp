#include "bishop.h"

bool Bishop::moveRestrictions(const Piece *nextpiece, const QPoint &nextPos)
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

	if (abs(next_x - curr_x) == abs(next_y - curr_y))
		return true;
	else
		return false;
};

Bishop::Bishop(QColor color, QPoint Pos) : Piece('B', color, Pos){};
