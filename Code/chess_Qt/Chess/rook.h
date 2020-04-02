#pragma once
#include "piece.h"

class Rook : public Piece
{
public:
    bool moveRestrictions(Piece *nextpiece, QPoint nextPos);

    Rook(char id, QColor color, QPoint Pos);

private:
};
