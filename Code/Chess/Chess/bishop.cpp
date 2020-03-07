#include "bishop.h"

bool Bishop::moveRestrictions(Piece* nextpiece, Position nextPos, const Color& playerColor)
{
	return true;
}

Bishop::Bishop(char id, Color color, Position Pos) : Piece(id, color, Pos) {};
