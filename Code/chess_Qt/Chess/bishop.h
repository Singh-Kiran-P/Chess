#pragma once
#include "piece.h"

class Bishop : public Piece
{
public:
    bool moveRestrictions(Piece *nextpiece, QPoint nextPos);

    Bishop(char id, QColor color, QPoint Pos);

private:
};
