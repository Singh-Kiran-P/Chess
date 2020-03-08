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
	virtual bool moveRestrictions(Piece* nextpiece, Position nextPos, const Color &playerColor) = 0;

	Piece(char id, Color color, Position Pos);
private:
    char m_id;
	Position m_position;
	Color m_color;
	bool m_killed = false;
};
