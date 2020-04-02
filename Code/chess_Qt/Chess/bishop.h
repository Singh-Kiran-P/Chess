#pragma once
#include "piece.h"

class Bishop : public Piece
{
public:
    bool moveRestrictions(Piece *nextpiece, Position nextPos);

    Bishop(char id, QColor color, Position Pos);

private:
};
