#pragma once
#include "piece.h"

class Rook : public Piece {
public:
	bool moveRestrictions(Piece* nextpiece, Position nextPos, const Color& playerColor);

	Rook(char id, Color color, Position Pos);
private:

};

