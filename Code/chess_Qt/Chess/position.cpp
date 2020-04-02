#include "position.h"
#include <string>
const int SIZE_BOARD = 8;

int Position::getx() const
{
	return m_xpos;
};

int Position::gety() const
{
	return m_ypos;
}
char Position::getYstr() const
{
	char c = 'A';
	char res = c + m_ypos;

	return res;
};

void Position::setpos(int x, int y)
{
	m_xpos = x;
	m_ypos = y;
};

void Position::setpos(QString pos)
{
	m_ypos = pos[0].unicode() - 'A';
	m_xpos = SIZE_BOARD - (pos[1].digitValue());
};

Position::Position(int x, int y) : m_xpos{x}, m_ypos{y} {};

Position::Position(QString pos) : m_xpos{SIZE_BOARD - (pos[1]).digitValue()}, m_ypos{pos[0].unicode() - 'A'} {};
