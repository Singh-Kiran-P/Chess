#ifndef PIECE
#define PIECE
#include "position.h"
#include "color.h"

class Piece {
    public:
        bool move(Piece p, Position pos) const;
    private:
        Position m_position;
        Color m_color;
        bool m_killed;
};

#endif
