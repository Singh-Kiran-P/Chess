#pragma once
#include "piece.h"

class Bishop : public Piece {
public:
	bool moveRestrictions(Piece* nextpiece, Position nextPos);

	Bishop(char id, Color color, Position Pos);
private:

};
