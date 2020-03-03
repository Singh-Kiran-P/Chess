#ifndef PAWN
#define PAWN
#include "color.h"
#include "position.h"

class Pawn {
	public:
		char getId();
		void setId(char id);

		void setColor(Color color);
		Color getColor();

		int turnCount();
		void increaseTurnCount();

		bool moveRestrictions(int curr_x, int curr_y, int next_x, int next_y, Pawn* movingpiece, Pawn* nextpiece);

	private:
		char m_id;
		int m_turnCount = 0;
		Color m_color;
		bool m_killed = false;
};

#endif
