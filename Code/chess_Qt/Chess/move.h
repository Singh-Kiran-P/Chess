#pragma once
#include <string>
#include "position.h"
#include "color.h"
#include "board.h"

class Move {
    public:
        Move(char id, Color color, Position currPos, Position nextPos);
        std::string ColorToStr(Color color);

        void print();

    private:
        char m_Id;
        Color m_color;
        Position m_currPos;
        Position m_nextPos;

};
