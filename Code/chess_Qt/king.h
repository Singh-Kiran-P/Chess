#pragma once
#include "piece.h"
class King : public Piece
{
public:
    bool moveRestrictions(const Piece *nextpiece, const QPoint &nextPos);
    King(QColor color, QPoint Pos);
};
