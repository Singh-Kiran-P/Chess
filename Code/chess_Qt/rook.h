#pragma once
#include "piece.h"

class Rook : public Piece
{
public:
    bool moveRestrictions(const Piece *nextpiece, const QPoint &nextPos);

    Rook(QColor color, QPoint Pos);

private:
};
