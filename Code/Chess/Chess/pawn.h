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

		bool firstTurn();
		void setfirstTurnFalse();

	private:
		char m_id;
		bool m_firstTurn = true;
		Color m_color;
		bool m_killed = false;
};

#endif
