#include "position.h"
#include <string>
const int SIZE_BOARD = 8;

int Position::getx() const {
	return m_xpos;
};

int Position::gety() const {
	return m_ypos;
}
char Position::getYstr() const
{
	char c = 'A';
	char res = c + m_ypos;

	return res;
}
;

void Position::setpos(int x, int y) {
	m_xpos = x;
	m_ypos = y;
};

void Position::setpos(std::string pos)
{
	m_ypos = (char)pos[0] - 'A';
	m_xpos = SIZE_BOARD - (stoi(pos.substr(1)));
};

Position::Position(int x, int y) : m_xpos{x}, m_ypos{y} {};

Position::Position(std::string pos) : m_xpos{SIZE_BOARD - (stoi(pos.substr(1)))}, m_ypos{(char)pos[0] - 'A'} {};
