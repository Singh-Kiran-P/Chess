#pragma once
#include "piece.h"

class Rook : public Piece
{
public:
    bool moveRestrictions(Piece *nextpiece, Position nextPos);

    Rook(char id, QColor color, Position Pos);

private:
};
