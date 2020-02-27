#ifndef POSITION
#define POSITION

class Position {
    public:
    int getx();
    int gety();

    void setpos(int x, int y);

    private:
        int m_xpos;
        int m_ypos;
};

#endif
