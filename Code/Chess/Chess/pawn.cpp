#include "pawn.h"

int Pawn::turnCount() const {
	return m_turnCount;
};

void Pawn::increaseTurnCount() {
	m_turnCount++;
};

bool Pawn::moveRestrictions(int curr_x, int curr_y, int next_x, int next_y, Piece* movingpiece, Piece* nextpiece) {


	if (movingpiece->getColor() == Color::White) {
        int max_delta_x = -1;
        if (((Pawn*)movingpiece)->turnCount() == 0)
            max_delta_x--;

        if (curr_y == next_y && (max_delta_x <= (next_x - curr_x) && (next_x - curr_x) < 0)) {
            if (nextpiece == nullptr)
                return true;
            else
                return false;
        }
        else if (abs(curr_y - next_y) == 1 && (next_x - curr_x) == -1 && nextpiece != nullptr) {
                if (movingpiece->getColor() != nextpiece->getColor())
                    return true;
                else
                    return false;
        }
    }

    else if (movingpiece->getColor() == Color::Black) {
        int max_delta_x = 1;
        if (((Pawn*)movingpiece)->turnCount() == 0)
            max_delta_x++;

            if (curr_y == next_y && (0 < (next_x - curr_x) && (next_x - curr_x) <= max_delta_x)) {
                if (nextpiece == nullptr)
                    return true;
                else
                    return false;
            }
        else if (abs(curr_y - next_y) == 1 && (next_x - curr_x) == 1  && nextpiece != nullptr) {
                if (movingpiece->getColor() != nextpiece->getColor())
                    return true;
                else
                    return false;
        }
    }
	return false;
};
