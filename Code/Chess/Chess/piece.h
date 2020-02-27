#ifndef PIECE
#define PIECE
#include "position.h"
#include "color.h"

class Piece {
    public:
        void move(Piece p, Position pos);
    private:
        Position m_position;
        Color m_color;
        bool m_killed;
};

#endif
