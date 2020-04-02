#pragma once
#include "piece.h"
class Knight : public Piece
{
public:
    bool moveRestrictions(Piece *nextpiece, QPoint nextPos);
    Knight(char id, QColor color, QPoint Pos);

private:
};
