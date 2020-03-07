#include "knight.h"

bool Knight::moveRestrictions(Piece* nextpiece, Position nextPos, const Color& playerColor)
{
	return true;
}

Knight::Knight(char id, Color color, Position Pos) : Piece(id, color, Pos) {};

