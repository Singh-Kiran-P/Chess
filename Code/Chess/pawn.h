#pragma once
#include "piece.h"

class Pawn : public Piece
{
public:
	int turnCount() const;
	void increaseTurnCount();

    bool moveRestrictions(Piece *nextpiece, QPoint nextPos);

    Pawn(char id, QColor color, QPoint Pos);

private:
	int m_turnCount = 0;
};
