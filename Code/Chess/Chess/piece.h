#ifndef PIECE
#define PIECE
#include "position.h"
#include "color.h"

class Piece {
    public:
        char getId() const;
		void setId(char id);

		void setColor(Color color) ;
		Color getColor() const;

        virtual bool moveRestrictions(int curr_x, int curr_y, int next_x, int next_y, Piece* movingpiece, Piece* nextpiece) = 0;

    private:
        char m_id;
        Position m_position;
        Color m_color;
        bool m_killed = false;
};

#endif
