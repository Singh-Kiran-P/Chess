#include "rook.h"

bool Rook::moveRestrictions(Piece* nextpiece, Position nextPos)
{
	return true;
}

Rook::Rook(char id, Color color, Position Pos) :Piece(id, color, Pos) {};