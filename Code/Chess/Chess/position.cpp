#include "position.h"
#include <string>
int Position::getx() {
	return m_xpos;
};

int Position::gety() {
	return m_ypos;
};

void Position::setpos(int x, int y) {
	m_xpos = x;
	m_ypos = y;
}
void Position::setpos(std::string pos)
{

	m_ypos = (char)pos[0] - 'A';
	m_xpos = (stoi(pos.substr(1))) - 1;
};
