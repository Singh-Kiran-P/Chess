#pragma once
#include "piece.h"
class King : public Piece
{
public:
    bool moveRestrictions(Piece *nextpiece, QPoint nextPos);
    King(char id, QColor color, QPoint Pos);

private:
	bool castlingDone = false;
};
