#include "rook.h"

bool Rook::moveRestrictions(Piece* nextpiece, Position nextPos, const Color& playerColor)
{
	return true;
}

Rook::Rook(char id, Color color, Position Pos) :Piece(id, color, Pos) {};