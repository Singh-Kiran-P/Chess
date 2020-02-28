#include "pawn.h"

bool Pawn::check_move(Position moveTo)
{
	return true;
}

char Pawn::getId()
{
	return m_id;
};

void Pawn::setId(char id)
{
	m_id = id;;
};

void Pawn::setColor(Color color) {
	m_color = color;
};

bool Pawn::firtsTurn()
{
	return m_firstTurn;
}

void Pawn::setfirstTurnFalse()
{
	m_firstTurn = false;
}

Color Pawn::getColor() {
	return m_color;
}
