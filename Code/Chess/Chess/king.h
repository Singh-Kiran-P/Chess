#pragma once
#include "piece.h"
class King : public Piece {
public:
	bool moveRestrictions(Piece* nextpiece, Position nextPos, const Color& playerColor);
	King(char id, Color color, Position Pos);

private:
	bool castlingDone = false;
};