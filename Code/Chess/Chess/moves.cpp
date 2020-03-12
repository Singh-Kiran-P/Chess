#include "moves.h"

Moves::Moves(char id, Color color, Position currPos, Position nextPos) :m_color{ color }, m_PieseId{ id }, m_currPos{ currPos }, m_nextPos{ nextPos }{}

char Moves::getId() const
{
	return m_PieseId;
}
string Moves::getColor() const
{
	if (m_color==Color::Black)
	{
		return "(Black)";
	}
	else {
		return "(White)";
	}
}
Position Moves::getCurrPos() const
{
	return m_currPos;
}
Position Moves::getNextPos() const
{
	return m_nextPos;
}
void Moves::addMove(char id,Color color, Position curr, Position next)
{

	Moves m(id,color,curr, next);
	m_moves.push_back(m);
}
void Moves::print() const
{
	for (int i = 0; i < m_moves.size(); i++) {
		std::cout <<endl<<"Id:"<< m_moves.at(i).getId()<< m_moves.at(i).getColor()<< " from: x="<<m_moves.at(i).getCurrPos().getx()
			<<" y="<<  m_moves.at(i).getCurrPos().getYstr()
			<< " To: x="<< m_moves.at(i).getNextPos().getx()
			<< " y=" << m_moves.at(i).getNextPos().getYstr()
			<<endl;
	}
}
;
