#pragma once
#include "piece.h"
class Knight : public Piece
{
public:
    bool moveRestrictions(const Piece *nextpiece, const QPoint &nextPos);
    Knight(QColor color, QPoint Pos);

private:
};
