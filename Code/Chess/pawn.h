#pragma once
#include "piece.h"

class Pawn : public Piece
{
public:
	int turnCount() const;
	void increaseTurnCount();

    bool moveRestrictions(const Piece *nextpiece, const QPoint &nextPos);

    Pawn(QColor color, QPoint Pos);

private:
	int m_turnCount = 0;
};
