#ifndef PAWN
#define PAWN
#include "color.h"
#include "position.h"
#include <string>

class Pawn {
public:
	std::string getName();
<<<<<<< HEAD
=======
	void setName(std::string name);
	bool move(Position moveTo);
>>>>>>> e65d8478c8dfd27ce2b4f72a84dcf5fe1eaf09c3

private:
	bool check_move(Position moveTo);

	std::string m_name =".";
	bool m_firstTurn;
	Position m_position;
	Color m_color;
	bool m_killed;
};


#endif // !PAWN
