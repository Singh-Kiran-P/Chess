#ifndef PLAYER
#define PLAYER
#include <string>
#include "color.h"
using namespace std;

class Player {
    public:
        void setcolor(Color color);
    private:
        string m_playername;
        Color m_color;
};

#endif
