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
	


};
