#include "queen.h"

bool Queen::moveRestrictions(Piece* nextpiece, Position nextPos, const Color& playerColor)
{
	return true;
}
Queen::Queen(char id, Color color, Position Pos) :Piece(id, color, Pos) {};
