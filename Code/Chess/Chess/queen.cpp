#include "queen.h"

bool Queen::moveRestrictions(Piece* nextpiece, Position nextPos)
{
	return true;
}
Queen::Queen(char id, Color color, Position Pos) :Piece(id, color, Pos) {};
