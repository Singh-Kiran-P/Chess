#ifndef PAWN
#define PAWN
#include "color.h"
#include "position.h"
#include <string>

class Pawn {
public:
	std::string getName();
	void setName(std::string name);

private:
	bool check_move(Position moveTo);

	std::string m_name =".";
	bool m_firstTurn;
	Position m_position;
	Color m_color;
	bool m_killed;
};


#endif // !PAWN