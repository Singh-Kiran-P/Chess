#pragma once
#include "position.h"
#include <QColor>
#include <iostream>

class Piece
{
public:
	QColor getColor() const;
	Position getPos();
	void setPos(Position p);

	char getId();
	virtual bool moveRestrictions(Piece *nextpiece, Position nextPos) = 0;

	Piece(char id, QColor color, Position Pos);

protected:
	Position m_position;
	QColor m_color;

private:
	char m_id;
};
