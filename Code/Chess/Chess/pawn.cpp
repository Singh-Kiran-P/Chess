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
