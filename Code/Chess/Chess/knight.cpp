#include "knight.h"

bool Knight::moveRestrictions(Piece* nextpiece, Position nextPos)
{
	return true;
}

Knight::Knight(char id, Color color, Position Pos) : Piece(id, color, Pos) {};

