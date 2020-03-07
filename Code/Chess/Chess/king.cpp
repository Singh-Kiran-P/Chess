#include "king.h"

bool King::moveRestrictions(Piece* nextpiece, Position nextPos, const Color& playerColor)
{
	return true;
}

King::King(char id, Color color, Position Pos) : Piece(id, color, Pos) {};
