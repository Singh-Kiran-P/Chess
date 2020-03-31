#pragma once
#include <string>

class Position {
    public:
    int getx() const;

    int gety() const;
    char getYstr() const;

    void setpos(int x, int y);
    void setpos(std::string pos);

    Position() {};
    Position(int x, int y);
    Position(std::string pos);

    private:
        int m_xpos;
        int m_ypos;
};

