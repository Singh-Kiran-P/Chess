#pragma once
#include <string>
#include "position.h"
#include "board.h"
#include <QColor>

class Move
{
public:
    Move(char id, QColor color, Position currPos, Position nextPos);
    std::string ColorToStr(QColor color);

    void print();

private:
    char m_Id;
    QColor m_color;
    Position m_currPos;
    Position m_nextPos;
};
