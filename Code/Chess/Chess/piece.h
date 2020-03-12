#pragma once
#include "position.h"
#include "player.h"
#include "color.h"
#include "TermColor.hpp"
#include <iostream>

class Piece {
public:

	Color getColor() const;
	//Piece(const Piece& p2) { m_color = p2.m_color; m_position = p2.m_position; m_id = p2.m_id, m_killed = p2.m_killed; };//copy constuctor
	Position getPos();
	void setPos(Position p);

	char getId();
	virtual bool moveRestrictions(Piece* nextpiece, Position nextPos) = 0;

	Piece(char id, Color color, Position Pos);
protected:
	Position m_position;
	Color m_color;

private:
    char m_id;
	bool m_killed = false;
};
