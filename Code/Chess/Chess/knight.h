#pragma once
#include "piece.h"
class Knight : public Piece {
public:
	bool moveRestrictions(Piece* nextpiece, Position nextPos);
	Knight(char id, Color color, Position Pos);

private:

};