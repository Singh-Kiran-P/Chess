#include "move.h"

Move::Move(char id, QColor color, Position currPos, Position nextPos) : m_Id{id}, m_color{color}, m_currPos{currPos}, m_nextPos{nextPos} {};

std::string Move::ColorToStr(QColor color)
{
    if (color == Qt::black)
        return "(Black)";
    else
        return "(White)";
};

void Move::print()
{
    std::cout << "Id: " << m_Id << ColorToStr(m_color)
              << " From: " << (char)(m_currPos.gety() + 'A') << 8 - m_currPos.getx()
              << " To: " << (char)(m_nextPos.gety() + 'A') << 8 - m_nextPos.getx() << std::endl;
};
