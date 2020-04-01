#pragma once
#include <QString>

class Position {
    public:
    int getx() const;

    int gety() const;
    char getYstr() const;

    void setpos(int x, int y);
    void setpos(QString pos);

    Position() {};
    Position(int x, int y);
    Position(QString pos);

    private:
        int m_xpos;
        int m_ypos;
};

