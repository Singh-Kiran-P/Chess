#pragma once
#include "piece.h"

class Bishop : public Piece {
public:
	bool moveRestrictions(Piece* nextpiece, Position nextPos, const Color& playerColor);

	Bishop(char id, Color color, Position Pos);
private:

};
