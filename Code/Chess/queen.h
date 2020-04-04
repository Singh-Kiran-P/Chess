#pragma once
#include "piece.h"

class Queen : public Piece
{
public:
    bool moveRestrictions(Piece *nextpiece, QPoint nextPos);

    Queen(char id, QColor color, QPoint Pos);

private:
};
