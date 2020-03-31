#pragma once
#include "piece.h"

class Queen : public Piece {
public:
	bool moveRestrictions(Piece* nextpiece, Position nextPos);

	Queen(char id, Color color, Position Pos);
private:

};

