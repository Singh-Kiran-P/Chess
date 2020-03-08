#include "pawn.h"

int Pawn::turnCount() const {
	return m_turnCount;
};

void Pawn::increaseTurnCount() {
	m_turnCount++;
};

bool Pawn::moveRestrictions(Piece* nextpiece, Position nextPos, const Color &playerColor) {
	if (this->getColor() != playerColor)
		return false;

	Position currPos = this->getPos();
	int curr_x{ currPos.getx() };
	int curr_y{ currPos.gety() };

	int next_x{ nextPos.getx() };
	int next_y{ nextPos.gety() };

	int max_delta_x{ 1 };
	if (this->getColor() == Color::White) {
		if (next_x >= curr_x)
			return false;
	}

	else if (this->getColor() == Color::Black) {
		if (next_x <= curr_x)
			return false;
	}

	if (((Pawn*)this)->turnCount() == 0)
		max_delta_x = 2;

	if (curr_y == next_y && abs(next_x - curr_x) <= max_delta_x) {
		if (nextpiece == nullptr)
			return true;
		else
			return false;
	}
	else if (abs(curr_y - next_y) == 1 && abs(next_x - curr_x) == 1 && nextpiece != nullptr) {
		if (this->getColor() != nextpiece->getColor())
			return true;
		else
			return false;
	}	
	return false;
};

Pawn::Pawn(char id, Color color, Position Pos) : Piece(id, color, Pos) {};
