#include "rook.h"

bool Rook::moveRestrictions(Piece* nextpiece, Position nextPos) {
	int curr_x = m_position.getx();
	int curr_y = m_position.gety();

	int next_x = nextPos.getx();
	int next_y = nextPos.gety();

	if (nextpiece != nullptr) {
		if (nextpiece->getColor() == m_color)
			return false;
	}

	if ((curr_x == next_x) || (curr_y == next_y))
		return true;
	else
		return false;
};

Rook::Rook(char id, Color color, Position Pos) :Piece(id, color, Pos) {};
