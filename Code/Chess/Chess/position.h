#ifndef POSITION
#define POSITION
#include <string>
class Position {
    public:
    int getx();
    int gety();

    void setpos(int x, int y);
    void setpos(std::string pos);

    private:
        int m_xpos;
        int m_ypos;
};

#endif
