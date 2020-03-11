#include "queen.h"

bool Queen::moveRestrictions(Piece* nextpiece, Position nextPos) {

	int curr_x = m_position.getx();
	int curr_y = m_position.gety();

	int next_x = nextPos.getx();
	int next_y = nextPos.gety();

	if (curr_x == next_x && curr_y == next_y)
		return false;

	if (nextpiece != nullptr) {
		if (nextpiece->getColor() == m_color)
			return false;
	}


	if (abs(next_x - curr_x) == abs(next_y - curr_y) || (curr_y == next_y) || (curr_x == next_x))
		return true;
	else
		return false;


};

Queen::Queen(char id, Color color, Position Pos) :Piece(id, color, Pos) {};
