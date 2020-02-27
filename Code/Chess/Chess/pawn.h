#ifndef PAWN
#define PAWN
#include "color.h"
#include "position.h"
#include <string>

class Pawn {
public:
	std::string getName();
	void setName(std::string name);
	void setColor(Color color);
	bool firtsTurn();
	void setfirstTurnFalse();
	//Color getColor();

private:
	bool check_move(Position moveTo);

	std::string m_name =".";
	bool m_firstTurn = true;
	Color m_color;
	bool m_killed = false;
};


#endif // !PAWN
