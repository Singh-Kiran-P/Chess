#pragma once
#include "position.h"
#include "color.h"
#include <iostream>

class Piece {
	public:

		Color getColor() const;
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
};
