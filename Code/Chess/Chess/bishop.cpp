#include "bishop.h"

bool Bishop::moveRestrictions(Piece* nextpiece, Position nextPos)
{
	return true;
}

Bishop::Bishop(char id, Color color, Position Pos) : Piece(id, color, Pos) {};
