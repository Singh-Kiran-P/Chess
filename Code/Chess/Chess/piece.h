#ifndef PIECE
#define PIECE
#include "position.h"
#include "color.h"

class Piece {
    public:
		void setColor(Color color) ;
		Color getColor() const;
        
    private:
        Position m_position;
        Color m_color;
        bool m_killed = false;
};

#endif
