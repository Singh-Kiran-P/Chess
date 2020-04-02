#include "pawn.h"

int Pawn::turnCount() const
{
	return m_turnCount;
};

void Pawn::increaseTurnCount()
{
	m_turnCount++;
};

bool Pawn::moveRestrictions(Piece *nextpiece, Position nextPos)
{

	int curr_x{m_position.getx()};
	int curr_y{m_position.gety()};

	int next_x{nextPos.getx()};
	int next_y{nextPos.gety()};

	if (curr_x == next_x && curr_y == next_y)
		return false;

	int max_delta_x{1};
	if (m_color == Qt::white)
	{
		if (next_x >= curr_x)
			return false;
	}

	else if (m_color == Qt::black)
	{
		if (next_x <= curr_x)
			return false;
	}

	if (m_turnCount == 0)
		max_delta_x = 2;

	if (curr_y == next_y && abs(next_x - curr_x) <= max_delta_x)
	{
		if (nextpiece == nullptr)
			return true;
		else
			return false;
	}
	else if (abs(curr_y - next_y) == 1 && abs(next_x - curr_x) == 1)
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

Pawn::Pawn(char id, QColor color, Position Pos) : Piece(id, color, Pos){};
