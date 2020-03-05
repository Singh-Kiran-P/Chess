#pragma once
#include "position.h"
#include "color.h"

class Piece {
public:
	//char getId() const;
	//void setId(char id);

	void setColor(Color color);
	Color getColor() const;

	Position getPos();
	void setPos(Position p);
	virtual void printId(Piece* p) = 0;
	virtual bool moveRestrictions(Piece* movingpiece, Piece* nextpiece, int next_x, int next_y) = 0;

	Piece() {};
private:
	Position m_position;
	Color m_color;
	bool m_killed = false;
};

