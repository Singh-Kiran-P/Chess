#pragma once
#include "piece.h"
class Knight : public Piece
{
public:
    bool moveRestrictions(Piece *nextpiece, Position nextPos);
    Knight(char id, QColor color, Position Pos);

private:
};
