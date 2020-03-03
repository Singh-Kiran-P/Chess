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

		bool moveRestrictions();

	private:
		char m_id;
		int m_turnCount = 0;
		Color m_color;
		bool m_killed = false;
};

#endif
