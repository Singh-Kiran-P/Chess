#include "pawn.h"


bool Pawn::check_move(Position moveTo)
{
	return true;
}


std::string Pawn::getName()
{
	return m_name;
}

void Pawn::setName(std::string name)
{
	m_name = name;
}

void Pawn::setColor(Color color) {
	m_color = color;
}

Color getColor() {
	return m_color;
}
