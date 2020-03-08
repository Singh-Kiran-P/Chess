#pragma once
#include "position.h"
#include "player.h"
#include "color.h"
#include "TermColor.hpp"
#include <iostream>

class Piece {
public:

	void setColor(Color color);
	Color getColor() const;

	Position getPos();
	void setPos(Position p);

	char Id();
	virtual bool moveRestrictions(Piece* nextpiece, Position nextPos) = 0;

	Piece(char id, Color color, Position Pos);
protected:
	Position m_position;
	Color m_color;

private:
    char m_id;
	bool m_killed = false;
};
