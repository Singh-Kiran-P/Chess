#include "pawn.h"

int Pawn::turnCount() const {
	return m_turnCount;
};

void Pawn::increaseTurnCount() {
	m_turnCount++;
};

bool Pawn::moveRestrictions(Piece* movingpiece, Piece* nextpiece, int x, int y) {
	Position currPos = movingpiece->getPos();
	int curr_x = currPos.getx();
	int curr_y = currPos.gety();

	int next_x = x;
	int next_y = y;

	int max_delta_x = 1;
	if (movingpiece->getColor() == Color::White) {
		if (next_x >= curr_x)
			return false;
	}

	else if (movingpiece->getColor() == Color::Black) {
		if (next_x <= curr_x)
			return false;
	}

	if (((Pawn*)movingpiece)->turnCount() == 0)
	max_delta_x = 2;

    if (curr_y == next_y && abs(next_x - curr_x) <= max_delta_x) {
        if (nextpiece == nullptr)
            return true;
        else
            return false;
    }
    else if (abs(curr_y - next_y) == 1 && abs(next_x - curr_x) == 1 && nextpiece != nullptr) {
        if (movingpiece->getColor() != nextpiece->getColor())
            return true;
        else
        	return false;
    }
	return false;
};

