#include "piece.h"

QColor Piece::getColor() const
{
	return m_color;
};

QPoint Piece::getPos()
{
	return m_position;
};

void Piece::setPos(QPoint p)
{
	m_position = p;
};

char Piece::getId()
{
	return m_id;
};

Piece::Piece(char id, QColor color, QPoint Pos) : m_id{id}, m_color{color}, m_position{Pos} {};
