#pragma once
#include <string>
#include "position.h"
#include "color.h"
#include "TermColor.hpp"
using namespace std;

class Player {
    public:
        Color color() const;

        std::string name() const;

        virtual Position moveFrom(Color playerColor) = 0;
        virtual Position moveTo(Position currPos, Color playerColor) = 0;

        Player(string nameStr, Color color);

    private:
        string m_playername;
        Color m_color;
};
