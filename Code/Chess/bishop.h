#pragma once
#include "piece.h"

class Bishop : public Piece
{
public:
    bool moveRestrictions(const Piece *nextpiece, const QPoint &nextPos);

    Bishop(QColor color, QPoint Pos);

private:
};
