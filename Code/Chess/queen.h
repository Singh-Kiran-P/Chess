#pragma once
#include "piece.h"

class Queen : public Piece
{
public:
    bool moveRestrictions(const Piece *nextpiece, const QPoint &nextPos);

    Queen(QColor color, QPoint Pos);

private:
};
